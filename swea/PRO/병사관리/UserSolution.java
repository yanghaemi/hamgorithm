import java.util.*;

class UserSolution
{

	Node[] arr;
	Node[][] head;
	Node[][] tail;

	class Node{
		int mID;
		int mTeam;
		int mScore;
		Node prev;
		Node next;

		Node(int mID, int mTeam){
			this.mID = mID;
			this.mTeam = mTeam;
		}
	}

	public void init()
	{
		arr = new Node[100_001];
		// Arrays.fill(arr, new Node(-1, -1));

		head = new Node[6][6];
		tail = new Node[6][6];
		
		for(int t=1;t<=5;t++){
			for(int s=1;s<=5;s++){
				head[t][s] = new Node(-1, t);
				tail[t][s] = new Node(-1, t);
				head[t][s].next = tail[t][s];
				tail[t][s].prev = head[t][s]; 
			}
		}
	}
	
	public void hire(int mID, int mTeam, int mScore)
	{
		Node node = new Node(mID, mTeam);
		arr[mID] = node;

		Node h = head[mTeam][mScore];
		node.next = h.next;
		node.prev = h;
		h.next.prev = node;
		h.next = node;
	}
	
	public void fire(int mID)
	{
		Node node = arr[mID];

		node.prev.next = node.next;
		node.next.prev = node.prev;

		arr[mID] = null;
	}

	public void updateSoldier(int mID, int mScore)
	{
		Node node = arr[mID];
		if(node == null) return;

		node.prev.next = node.next;
		node.next.prev = node.prev;

		// 새로운 점수로 수정
		Node h = head[node.mTeam][mScore];
		node.next = h.next;
		node.prev = h;
		node.next.prev = node;
		h.next = node;
	}

	public void updateTeam(int mTeam, int mChangeScore)
	{
		if(mChangeScore == 0) return;
		if(mChangeScore > 0 ){
			for(int s = 4; s > 0; s--){
				int nextS = s + mChangeScore;
                if (nextS > 5) nextS = 5; // 5점 초과는 5점으로 보정
                moveList(mTeam, s, nextS);
			}
		}
		if(mChangeScore < 0){
			for(int s = 2; s<=5; s++){
				int nextS = s + mChangeScore;
                if (nextS < 1) nextS = 1; // 1점 미만은 1점으로 보정
                moveList(mTeam, s, nextS);
			}
		}
	}
	
	private void moveList(int mTeam, int src, int dest) {
		if (src == dest) return;
        
        Node srcHead = head[mTeam][src];
        Node srcTail = tail[mTeam][src];
        
        // 해당 점수대에 병사가 없으면 이동 안 함
        if (srcHead.next == srcTail) return;
        
        Node first = srcHead.next;
        Node last = srcTail.prev;
        
        // 1. 기존 src 리스트는 비워줍니다 (더미 헤드와 테일 직접 연결)
        srcHead.next = srcTail;
        srcTail.prev = srcHead;
        
        // 2. dest 리스트의 맨 앞으로 뭉텅이 채로 이어 붙입니다.
        Node destHead = head[mTeam][dest];
        Node destFirst = destHead.next;
        
        destHead.next = first;
        first.prev = destHead;
        
        last.next = destFirst;
        destFirst.prev = last;
	}

	public int bestSoldier(int mTeam)
	{
		for(int s = 5; s>0; s--){
			Node h = head[mTeam][s];
			Node t = tail[mTeam][s];
			
			if(h.next == t) continue;

			int maxID = 0;
			Node curr = h.next;
			while(curr != t){
				if(curr.mID > maxID){
					maxID = curr.mID;
				}
				curr = curr.next;
			}

			return maxID;
		}		

		return 0;
	}
}