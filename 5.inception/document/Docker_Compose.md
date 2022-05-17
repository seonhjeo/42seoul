# 도커 컴포즈

## 도커 컴포즈란
 - 여러개의 컨테이너를 하나로 묶어주는 역할을 하는 툴
 - 각각의 컨테이너의 Dockerfile 요구

## 도커 컴포즈 커맨드
 - 기본 사용법 : `docker-compose -OPTION COMMAND`
 - 옵션
   - -f : 특정 디렉토리의 컴포즈 파일을 실행시킨다
 - 커맨드
   - up : 도커 컴포즈에 정의된 모든 서비스 컨테이너를 생성하고 실행, -d 옵션으로 백그라운드 실행 가능
   - down : 도커 컴포즈에 정의된 모든 서비스 컨테이너를 정지시키고 삭제
   - start : 정지되어 있는 특정 컨테이너를 실행시키기 위해 사용
   - stop : 실행되고 있는 특정 서비스 컨테이너를 정지시키기 위해 사용
   - ps : 도커 컴포즈 내에 정의된 모든 서비스 컨테이너 목록 조회
   - exec : 실행 중인 서비스 컨테이너를 대상으로 특정 명령어를 날릴 때 사용
     - `docker-compose exec mariadb /bin/bash` : mariadb 컨테이너의 bash쉘 실행
   - run : 서비스 컨테이너의 특정 명령어를 일회성으로 실행할 때 사용


## 도커 컴포즈 작성법
 - 참고 자료 : https://cornswrold.tistory.com/448
 - 참고 자료 : https://velog.io/@ragnarok_code/Docker-%EC%BB%B4%ED%8F%AC%EC%A6%88

 - 기본 구조는 다음과 같다
```
version: "3.8"
services:
  redis: # 레디스 설정
  db: # 데이터베이스 설정
  web: # 웹 애플리케이션 설정
networks: # 네트워크 설정
volumnes: #볼륨 설정
```
 - 상세 예시는 다음과 같다.
```
version: "3.8" 
services: 
  redis: 
    image: redis:alpine 
    ports: 
      - "6379" 
    networks: 
      - frontend 
    deploy:
      replicas: 2
      update_config:
        parallelism: 2
        delay: 10s
      restart_policy:
        condition: on-failure
  db:
    image: postgres:9.4
    volumes:
      - db-data:/var/lib/postgresql/data
    networks:
      - backend
    deploy:
      placement:
        max_replicas_per_node: 1
        constraints:
          - "node.role==manager"
  vote:
    image: dockersamples/examplevotingapp_vote:before
    ports: 
      - "5000:80"
    networks: 
      - frontend
    depends_on:
      - redis 
    deploy:
      replicas: 2
      update_config:
        parallelism: 2
      restart_policy:
        condition: on-failure 
    ...
networks:
  frontend:
  backend:

volumnes:
  db-data:
```
 - build : build 항목은 해당 서비스 이미지를 빌드하기 위한 Dockfile이 위치하는 경로를 지정하기 위해 사용한다.
 - image : 데이터베이스나 캐시와 같으 애플리케이션은 이미지 저장소(repoitory)로 부터 이미지를 내려받아서 사용하는 것이 일반적이다. image 항목은 이미지 저장소로부터 내려받을 이미지의 이름과 태그를 명시하는데 사용된다
 - ports : 호스트와 컨테이너의 포트를 맵핑시켜주는데 사용이되다. 바인드가 필요한 호스트 포트와 컨테이너 포트를 지정해준다.
 - volumnes : volumnes항목은 볼륨 설정을 위해 사용된다. 마운트(mount)가 필요한 호스트의 경로와 컨테이너의 경로를 명시해준다.
 - depends_on : depends_on 항목은 서비스 간 의존 관계를 지정하기 위해 사용된다.
 - environment : environment는 환경 변수를 설정하기 위해 사용된다.
 - networks : 가입할 네트워크의 종류 작성