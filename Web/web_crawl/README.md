## Selenium & Beautiful Soup 설치
### Selenium 설치
```bash
pip install selenium
```
### Beautiful Soup 4 설치
```bash
pip install bs4
```

## Chrome 웹 드라이버
```bash 
Chrome://version
```
- 크롬 버전 확인하고 [chromedriver](https://sites.google.com/a/chromium.org/chromedriver/downloads)를 버전에 맞게 받는다.

## 파일 설명
### image.py
- 이미지 이름 가져옴
- 새로고침될 때 몇 개 중복 생겨서 `image_list.txt` 사용

### image_tag.py 
- `image:tag` 형식으로 파싱해서 `tag.txt`에 저장

### test.sh
- tag.txt 파일에서 `image:tag` 읽어서 docker run 시 `/etc/shadow` 파일에서 root에 대한 패스워드를 `output.txt`에 저장 

### test2.sh 
- `cat: can't open '/etc/shadow': Permission denied` 경우가 있어서 `test.sh`에서 cp로 /etc/shadow 복사해서 읽는 코드도 추가함
- irros 이미지의 경우 docker cp로 컨테이너 내 /etc/shadow 파일을 복사해올 수 없어서 기존의 코드(docker run 시 /etc/shadow 파일 읽는) 남겨놓음

### tag.txt 
- `image_list.txt`에서 하위 80개 이미지 대상으로 `image_tag.py` 돌린 결과 파일

### output.txt 
- test2.sh 결과 파일 
- `cat ouput.txt | grep root:::0:::::` 또는 Ctrl+F에서 `root:::0:::::` 검색해서 확인

