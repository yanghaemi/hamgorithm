# 20291번 파일 정리
# 파이썬으로 풀자~

n = int(input())   #배경화면에 있는 파일 개수 n에 입력받기
arr = []           # 파일 이름 넣을 배열 선언
extensions = {}            # 확장자 이름 넣을 dict

# 배열을 선언한 후에는 arr.append()를 사용하여 값을 배열에 추가해야 함.

for i in range(n):  # n번 반복
    file_name = input() # 파일 이름을 입력받음
    arr.append(file_name)

#특정 부분 문자열('.') 이후의 문자열을 가져오기!
for file_name in arr:
    extension = file_name.split(".")[-1] #파일 이름을 '.' 기준으로 분할하여 확장자 부분만 가져옴
    
    if extension in extensions:
        extensions[extension]+=1
    else:
        extensions[extension] = 1


for ext, count in sorted(extensions.items()):   
    print(ext, count)

