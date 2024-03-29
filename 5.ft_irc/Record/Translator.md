# 1.Introduction

인터넷 릴레이 채팅 또는 IRC는 인터넷 상의 텍스트 기반 통신 프로토콜입니다.

공개 또는 비공개 실시간 메시징을 제공합니다. 사용자는 직접 메시지를 교환하고 그룹 채널에 가입할 수 있습니다.

IRC 클라이언트는 채널에 가입하기 위해 IRC 서버에 연결합니다. IRC 서버가 서로 연결되어 네트워크를 형성합니다.

# 2.General rules
프로그램은 메모리가 부족한 경우에도 충돌하지 않아야 하며 예기치 않게 종료되지 않아야 합니다. 만일 이 상황이 발생할 경우 프로젝트가 작동하지 않는 것으로 간주되며 성적은 0이 됩니다.

소스 파일을 컴파일할 Makefile을 제출해야 합니다. 다시 연결되면 안 됩니다(relink)

Makefile에는 적어도 다음 규칙이 포함되어야 합니다. $(NAME), all, clean, flean, re.

c++와 플래그 -Wall -Wextra -Werror로 코드를 컴파일합니다.

코드는 C++ 98 표준을 준수해야 합니다. 그러므로, 플래그 -std=c++98이 추가되어도 컴파일 되어야 합니다. 

항상 최대한의 C++ 기능을 사용하여 개발하십시오(예: <string.h> 대신 <cstring>을 선택하십시오) C 함수를 사용할 수 있지만 가능하면 항상 C++ 버전을 선호합니다.

외부 라이브러리 및 Boost 라이브러리는 사용할 수 없습니다.

# 3.Mandatory Part
프로그램 : ircserv

파일 이름 : Makefile, *.{hpp, h}, *.cpp, *.tpp, *.ipp, 선택적인 구성파일

arguments : port(수신 포트),  password(연결 암호)

사용함수 
```
socket, setsockopt, getsockname, getprotobyname,
gethostbyname, getaddrinfo, freeaddrinfo, bind,
connect, listen, accept, htons, htonl, ntohs,
ntohl, inet_addr, inet_ntoa, send, recv, signal,
lseek, fstat, fcntl, poll (or equivalent)
```
**당신은 C++ 98에서 IRC 서버를 개발해야 합니다.**

클라이언트를 개발해서는 안 됩니다.

서버 간 통신을 처리해서는 안 됩니다.

실행 파일은 다음과 같이 실행됩니다.

./ircserv <port> <password>

 - port : IRC 서버가 수신 IRC 연결을 수신할 포트 번호입니다.
 - password : 연결 암호입니다. 서버에 연결하려는 모든 IRC 클라이언트가 필요합니다.

```cpp
평가 척도에 poll()이 언급되더라도 select(), kqueue() 또는 epoll()과 
같은 동등한 기능을 사용할 수 있습니다.
```

### 3.1 Requirements

서버는 동시에 여러 클라이언트를 처리할 수 있어야 하며 중단되지 않아야 합니다.

Forking은 허용되지 않습니다. 모든 I/O 작업은 차단되지 않아야 합니다.

이러한 모든 작업(read, write, but also listen, and so forth)을 처리하는 데 사용할 수 있는 poll()은 1개뿐입니다.

```cpp
비차단 파일 설명자(use non-blocking file descriptors)를 사용해야 하므로, 
poll()(or equivalent[동등한 기능]) 없이
읽기/복구 또는 쓰기/전송 기능을 사용할 수 있으며, 서버가 차단되지 않습니다.

그러나 시스템 리소스가 더 많이 소모됩니다.

따라서 poll()(또는 동등한 기능)을 사용하지 않고 파일 설명자(file descriptor)를
읽기/복구 하거나 쓰기/전송하려고 하면 등급이 0이 됩니다.
```

여러 IRC 클라이언트가 있습니다. 당신은 그것들 중 하나를 레퍼런스로 선택해야 합니다. 레퍼런스 클라이언트는 평가 프로세스 중에 사용됩니다.

레퍼런스 클라이언트는 오류 없이 서버에 연결할 수 있어야 합니다.

클라이언트와 서버 간의 통신은 TCP/IP(v4 또는 v6)를 통해 이루어져야 합니다.

레퍼런스 클라이언트를 서버와 함께 사용하는 것은 공식 IRC 서버와 함께 사용하는 것과 유사해야 합니다. 그러나 다음 기능만 구현하면 됩니다.
 - 레퍼런스 클라이언트를 사용하여 인증확인, 닉네임, 사용자 이름 설정, 채널 가입, 개인 메시지 송수신이 가능해야 합니다. (authenticate, nickname, a username, join a channel, send and receive private messages)
 - 한 클라이언트에서 채널로 전송되는 모든 메시지는 채널에 가입한 다른 모든 클라이언트로 전달되어야 합니다.
 - 연산자와 일반 사용자가 있어야 합니다.
 - 그런 다음 연산자별 명령을 구현해야 합니다.

**물론, 당신은 깨끗한 코드를 작성해야 합니다.**

### 3.2 For MacOS only

```cpp
MacOS는 다른 Unix OS와 같은 방식으로 write()를 구현하지 않으므로
fcntl()을 사용할 수 있습니다.
다른 유닉스 OS와 유사한 동작을 수행하려면 비차단 모드에서 파일 설명자를 사용해야 합니다.
```

```cpp
그러나 fcntl()을 다음과 같이만 사용할 수 있습니다.
fcntl(fd, F_SETFL, O_NONBLOCK);
다른 flag은 금지되어 있습니다.
```

### 3.3 Test example

가능한 모든 오류 및 문제(부분적인 데이터 수신, 낮은 대역폭 등)를 확인합니다.

서버에 보내는 모든 내용이 올바르게 처리되는지 확인하려면 nc를 사용하여 다음과 같은 간단한 테스트를 수행할 수 있습니다.

![Untitled](./image/Untitled.png)

ctrl+D를 사용하여 명령을 여러 부분으로 나눕니다. 'com', 'man', 'd\n' 순으로 입력합니다.

명령을 처리하려면 먼저 수신된 패킷을 집계하여 다시 작성해야 합니다.

# 4.Bonus part

다음은 IRC 서버에 추가할 수 있는 추가 기능으로, 실제 IRC 서버와 더욱 유사합니다.

**파일 전송을 처리합니다.**

**봇**

```
보너스 부분은 필수 부분이 완벽한 경우에만 평가됩니다. Perfect는 필수 부품이 일체적으로 수행되었으며 오작동 없이 작동함을 의미합니다. 필수 요건을 모두 충족하지 못한 경우 보너스 부분은 전혀 평가되지 않습니다.
```

# 5.Submission and peer-evaluation

평소처럼 Git 저장소에 과제를 제출합니다.

방어 중에는 리포지토리 내부의 작업만 평가됩니다. 파일 이름을 두 번 확인하여 파일 이름이 올바른지 확인하십시오.

프로젝트에 대한 테스트 프로그램이 제출되지 않거나 등급이 지정되지 않더라도 해당 프로그램을 만드는 것이 좋습니다.

이러한 테스트는 방어 중에 서버를 테스트하는 데 특히 유용할 수 있지만, 다른 ft_irc를 언젠가 평가해야 하는 경우에도 마찬가지입니다.

실제로 평가 과정에서 필요한 모든 테스트를 자유롭게 사용할 수 있습니다.
```
레퍼런스 클라이언트는 평가과정 중에 사용됩니다.
```