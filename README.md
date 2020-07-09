# addressbook
>CURD 기능을 가진 간단 주소록 프로그램

addr_book.txt 파일을 읽어와 해당 주소록의 출력, 검색, 추가, 삭제, 파일저장 기능을 가진 주소록 프로그램입니다.  

## 사용한 IDE 및 언어
* visual studio 2019
* C

## 프로그램 구조  
 <img src ="./readme_img/project.png">

## 프로그램 시연
일부화면
- Main menu    
  <img src ="./readme_img/menu.JPG" width="50%" height="50%">  

-  Display address list   
  <img src ="./readme_img/display.JPG" width="50%" height="50%">

**실행 영상**  
<https://drive.google.com/file/d/1k9JB58t_yLmp7D2FPVTxStXlC32inDph/view?usp=sharing>


## 실행하기

cmd:  
별도의 설치할 파일 없이 프로젝트 디렉토리에서 cmd창에서 exe파일 실행
```
address.exe addr_book.txt
```

visual studio:
1. 구성 속성 - 디버깅 - 명령인수 addr_book.txt 적용
2. release x86으로 실행
