# 소켓 프로그래밍

### 1.소켓 생성
`int socket(int domain, int type, int protocol);`
 - man page : https://man7.org/linux/man-pages/man2/socket.2.html
 - 설명
   - socket함수로 소켓을 생성한다.
 - 매개변수
   - domain : 통신 도메인을 설정
   - type : 통신 타입을 설정
   - protocol : 소켓과 같이 사용되는 특수한 프로토콜 설정(기본 : 0)
 - 반환값
   - 성공 시 새 소켓의 파일 디스크럽터 반환
   - 실패 시 0 이하의 값 반환, errno존재

### 2. 소켓 옵션 설정
`int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);`

 - man page : https://man7.org/linux/man-pages/man2/setsockopt.2.html
 - 설명
   - 파일 디스크럽터 sockfd에 의해 참조되는 소켓에 대한 조작 옵션이다. 옵션은 여러 프로토콜 레벨에 존재할 수 있으며, 항상 최상위 소켓 레벨에 있다.
 - 매개변수
   - sockfd : 조작할 소켓의 id
   - level : SOL_SOCKET으로 특정됨
   - optname : `<sys/socket.h>`에 정의된 소켓 레벨 옵션.
   - optval, optlen : `setsockopt`의 옵션값에 접근하기 위한 값, 대체로 int형의 값 1의 레퍼런스와 사이즈로 지정
 - 반환값
   - 성공시 0, 실패시 -1

### 3. 소켓을 논블로킹으로 설정
`int fcntl(int fd, int cmd, ... /* arg */ );`
 - man page : https://man7.org/linux/man-pages/man2/fcntl.2.html
 - 설명
   - fcntl()은 열린 파일 설명자 fd에서 여러 작업 중 하나를 수행한다. 작업은 cmd에 의해 결정된다.
   - 소켓 또한 하나의 파일 디스크럽터이기 때문에 fcntl로 소켓을 논블로킹 모드로 변환한다.
 - 매개변수는 cmd의 종류에 따라 늘어날 수 있다.
   - 해당 과제에서는 `fcntl(sockfd, F_SETFL, O_NONBLOCK)`모드를 이용한다.
 - 반환값
   - 성공시 0을 포함한 양수(cmd에 따라 달라진다) 반환
   - 실패시 -1 반환

### 4. sockaddr_in 구조체 만들기
 - document : https://techlog.gurucat.net/292
 - 설명
   - ipv4를 사용할 때 쓰게 되는 구조체이다.
 - 구조체
```
struct sockaddr_in {
	short    sin_family;          // 주소 체계: AF_INET
	u_short  sin_port;            // 16 비트 포트 번호, network byte order
	struct   in_addr  sin_addr;   // 32 비트 IP 주소
	char     sin_zero[8];         // 전체 크기를 16 비트로 맞추기 위한 dummy(반드시 모두 0으로 채우기)
};
```
 - 초기화 및 사용
```
struct sockaddr_in serv_address = {};

memset(&serv_address, 0, sizeof(serv_address));

serv_address.sin_family = AF_INET;
serv_address.sin_addr.s_addr = INADDR_ANY;
serv_address.sin_port = htons(_portNumber);
```
 - htons 함수
   - https://man7.org/linux/man-pages/man3/htons.3p.html
   - 데이터를 네트워크 바이트순서로 변환

### 4. 소켓을 sockaddr구조체와 바인드
`int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`
 - man page : https://man7.org/linux/man-pages/man2/bind.2.html
 - document : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sanghun0318&logNo=220295678064
 - 매개변수
   - sockfd : 소켓 함수로 생성된 fd
   - addr, arrdlen : 위에서 sockaddr구조체와 그 크기
 - 반환값
   - 성공시 0, 실패시 -1반환

### 5. 소켓을 연결 요청 대기상태로 만들기
`int listen(int sockfd, int backlog);`
 - man page : https://man7.org/linux/man-pages/man2/listen.2.html
 - document : https://mintnlatte.tistory.com/280
 - 매개변수
   - sockfd : 소켓 함수로 생성된 fd
   - backlog : 연결 요청 대기 큐의 크기

### 6. 소켓을 논블로킹 상태로 만들기
`int poll(struct pollfd *fds, nfds_t nfds, int timeout);`
 - man page : https://man7.org/linux/man-pages/man2/poll.2.html
 - document : https://www.it-note.kr/23


