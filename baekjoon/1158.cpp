#include <iostream>
#include <vector>
using namespace std;
// 연결리스트 사용!
typedef struct node
{
    int data;          // 숫자
    struct node *next; // 다음 노드 포인터
} node;                // 노드

node *head = (node *)malloc(sizeof(node)); // head 생성
int n, k;                                  // 입력 양식
int Copy_n;

void headnode(int data)
{
    head->data = data;
    head->next = NULL;
    return;
}

void insert(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data; // newnode에 데이터 넣어주기
    newnode->next = NULL;

    node *cur = head;

    while (cur->next != NULL)
    {
        cur = cur->next; // cur을 마지막 노드까지 이동
    }
    cur->next = newnode;

    if (data == n)
    {
        newnode->next = head; // 원형 연결리스트
                              // 마지막 노드의 next를 head를 가리키게 함
    }
}

void deletenode(int k)
{
    node *cur = head;
    if (k == 1) // k가 1일 때 별도처리
    {
        node *temp = head;
        head = head->next;
        cout << temp->data;
        delete temp;
        return;
    }
    for (int i = 0; i < k - 2; i++)
    {
        cur = cur->next;
    }
    node *temp = cur->next;
    cur->next = cur->next->next;

    head = cur->next;
    cout << temp->data;
    delete temp;

    Copy_n--;

    return;
}

int main()
{
    cin >> n >> k;
    Copy_n = n;
    if (n == 1)
    {
        cout << "<1>";
        return 0;
    }
    headnode(1); // 1은 헤드로 삽입
    if (n >= 2)
    {
        for (int i = 2; i <= n; i++)
        {
            insert(i); // 2~n까지 연결리스트 연결
        }
    }

    cout << "<";

    for (int j = 0; j < n - 1; j++)
    {
        deletenode(k);
        cout << ", ";
    }
    deletenode(k);
    cout << ">";
}