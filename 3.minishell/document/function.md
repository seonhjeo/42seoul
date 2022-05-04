# 사전 지식

 - 참조 : https://velog.io/@hidaehyunlee/minishell-1.-%EA%B3%BC%EC%A0%9C%EC%86%8C%EA%B0%9C-%EB%B0%8F-%EC%84%A0%ED%96%89%EC%A7%80%EC%8B%9D

# 사용 함수들

 - 참조 : https://velog.io/@dogfootbirdfoot/Minishell-function

## 1. readline

### readline
```
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char* readline (const char *prompt);
```
 - 컴파일 시 `-lreadline`플래그로 라이브러리를 연결해 주어야 한다.
 - prompt를 프롬프트로써 사용하면서, 터미널로부터 읽어온 한 줄을 반환한다. 만일 prompt가 NULL 혹은 빈 문자열이면, 프롬프트가 실행되지 않는다.
 - 반환되는 라인은 `malloc(3)`을 사용하여 할당되므로 사용자는 종료 전에 free를 해주어야 한다.
 - 반환되는 라인은 개행 문자가 없는 텍스트만이 반환된다.
 - 빈 라인이 입력되면 빈 문자열을 반환한다. 라인을 읽는 도중 EOF를 만나고, 라인이 비어있으면 NULL을 반환한다. 비어있지 않으면 EOF는 개행문자로 취급한다.


### rl_on_new_line
```
int rl_on_new_line(void);
```
 - 업데이트 함수에 새로운(빈) 라인으로 이동했다고 알린다. 일반적으로 개행을 출력한 후 선언한다.

### rl_replace_line
```
void rl_replace_line(const char *text, int clear_undo);
```
 - `rl_line_buffer`의 내용을 텍스트로 바꾼다. 가능한 경우 포인트와 마크는 보존딘다. clear_undo가 0이 아니면 현재 줄과 관련된 실행 취소 목록이 지워진다.

### rl_redisplay
```
void rl_redisplay (void)
```
 - 현재 rl_line_buffer의 내용을 반영하여 화면에 표시되는 내용을 변경한다.

### add_history
```
void add_history (char *line);
```
 - readline 으로 불러온 char *line 를 인자로 넣으면 history 구조체에 추가해준다.(히스토리 목록 마지막에 추가. 알아서 관리됨.) 이 구조체는 <readline/history.h> 에 내장되어있다.


## 2. process

### fork
```
#include <unistd.h>
pid_t fork(void)
```
 - 현재 실행되는 프로세스에 대한 복사본 프로세스를 생선한다.
 - 자식 프로세스는 0을, 부모 프로세스는 자식 프로세스의 pid값을 반환받음. 실패시 -1을 반환함

### wait
```
#include <sys/wait.h>
pid_t wait(int *status);
```
 - 부모 프로세스가 자식 프로세스가 종료될 때까지 아무 일도 하지 않고 기다려주게 하는 함수.
 - status에는 자식 프로세스의 종료 상태 정보가 저장됨.
   - 정상 종료시 하위 8비트에 0, 상위 8비트에 프로세스가 종료되기 한 exit함수의 인수 기록
   - 비정상 종료시 하위 8비트에 프로세스를 종료시킨 시그널 번호, 상위 8비트에 0이 저장됨

### waitpid
```
#include <sys/wait.h>
pid_t waitpid(pid_t pid, int *status, int options)
```
 - wait()함수와 유사하나 wait()함수가 자식 프로세스중 어느 하나라도 종료되면 대기에서 풀리지만 waitpid()함수는 특정 자식 프로세스가 종료될 때까지 대기한다.
 - pid는 감시할 자식 프로세스의 pid를, option에는 대기를 위한 옵션을 인자로 준다.

### wait3
```
#include <sys/wait.h>
pid_t wait3(int *statloc, int options, struct rusage *rusage)
```
 - 자식 프로세스가 종료되는 것을 기다리며, 종료된 프로세스의 상태와 자원 사용량을 알려주는 함수
 - 인자 :
   - statloc : 자식 프로세스의 종료 상태를 나타내는 정보를 담는다.
   - options : 프로세스의 종료 상태 체크 시 옵션을 걸 수 있다.
   - rusage : 자식 프로세스의 리소스 사용량에 대한 정보가 담긴다.
 - 반환값 : 성공시 Process ID, 실패시 -1, WNOHANG 옵션으로 실행되고, 자식 프로세스가 아직 종료되지 않았으면 0 return

### wait4
```
#include <sys/wait.h>
pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage)
```
 - wait3와 동일하나 pid에 해당하는 프로세스만을 기다린다.

### statloc과 option의 사용 가능 매크로들

`statloc`
 - WIFEXITED(status)	: 자식 프로세스가 정상적으로 종료된 경우 true
 - WEXITESTATUS(status)	: exit()의 인자에서 하위 8비트 값을 리턴
 - WIFSIGNALED(status)	: 자식 프로세스가 시그널을 받아 비정상적으로 종료된 경우 true
 - WIFTERMSIG(status)	: 시그널 번호를 리턴
 - WIFCOREDUMP(status)	: 코어 파일이 생성된 경우 true
 - WIFSTOPPED(status)	: 현재 중지 상태이면 true
 - WSTOPSIG(status)		: 실행을 중단시킨 시그널 번호를 리턴
 - WIFCONTINUED(status)	: 작업 제어 중지 이후 실행이 재개되었으면 true

`option`
 - WCONTINUED	: 중지되었다가 실행을 재개한 이후 상태가 아직 보고되지 않은 자식도 리턴
 - WNOHANG		: 종료 상태를 즉시 회수 할 수 없는 상황이라고 하여도 waitpid() 호출이 차단되지 않고 0 리턴
 - WUNTRACED	: 중지되었으나 그 상태가 아직 보고되지 않은 자식도 리턴

## signal

### signal
 - 참조 : http://forum.falinux.com/zbxe/index.php?document_srl=413254&mid=C_LIB
```
#include <signal.h>
void (*signal(int sig, void (*func)(int)))(int);
```
 - 시그널 처리를 설정한다. 즉 어떤 시그널이 발생하면 기존 방법으로 처리할지, 아니면 무시하게 할지, 아니면 프로그램에서 직접 처리할지를 설정할 수 있다.
 - 설정 옵션은 다음과 같다.
   - SIG_DFL : 기존 방법을 따른다.
   - SIG_IGN : 시그널을 무시한다.
   - 함수이름 : 시그널이 발생하면 지정된 함수를 호출한다.
 - 인자 sig는 시그널 번호, 인자 *func는 시그널을 처리할 핸들러이다.
 - 반환값으로는 void *()(int);형식의 이전에 설정된 시그널 핸들러를 반환한다.

### kill
```
#include <signal.h>
int kill(pid_t pid, int sig);
```
 - kill() 함수는 쉘에서 프로세스를 죽이는 kill 명령과는 달리 프로세스에 시그널을 전송gksek. 프로세스에 SIGKILL을 보내면 쉘 명령의 kill과 같은 역할을 한다.
 - kill() 함수는 특정 프로세스 뿐만 아니라 같은 그룹 ID가 같은 모든 프로세스에게 동시에 시그널을 전송할 수 있으며, 권한 안에 있는 모든 프로세스에게도 시그널을 전송할 수 있다.
 - 첫 번째 인수는 pid는 KILL 대상 프로세스 ID, 두 번째 인수 sig는 시그널 번호이다. pid는 프로세스 ID 값에 따라 아래와 같이 처리가 분류됩니다.
   - 양수 : 지정한 프로세스 ID에만 시그널을 전송
   - 0 : 함수를 호출하는 프로세스와 같은 그룹에 있는 모든 프로세스에 시그널을 전송
   - -1 : 함수를 호출하는 프로세스가 전송할 수 있는 권한을 가진 모든 프로세스에 시그널을 전송
   - -1 이외의 음수	: 첫 번째 인수 pid 의 절대값 프로세스 그룹에 속하는 모든 프로세스에 시그널을 전송

### exit
 - 참조 : https://codetravel.tistory.com/28
```
#include <stdlib.h>
void exit(int status);
```
 - 일반적으로 프로세스를 종료할 때 return()함수와 동일하게 사용된다.


## files/directory

### getcwd
```
#include <unistd.h>
char *getcwd(char *buf, size_t size);
```
 - 현재 작업중인 디렉토리의 절대 경로를 buf에 복사하고 buf의 포인터를 리턴한다.
 - 인자 `buf`는 작업 디렉토리의 문자열을 담을 버퍼이고 `size`는 버퍼의 크기이다.
 - buf가 NULL이면 공백이 할당되고, size는 무시된다. 버퍼가 작으면 에러가 발생할 수 있으므로 크게 잡는다.
 - 성공시 현재 작업 디렉토리를, 실패시 NULL포인터를 리턴, errno를 설정한다.

### chdir
```
#include <unistd.h>
int chdir(const char *path);
```
 - 현재 작업 디렉토리를 변경한다. (change directory)
 - 디렉토리의 실행 권한이 있어야한다. path의 시작이 '\'이면 안된다.
 - 성공시 0, 실패시 -1 리턴, errno에 저장한다.

### stat
```
#include <sys/stat.h>
int stat(const char *path, struct stat *buf)
```
 - 파일의 크기, 권한, 생성일시, 최종 변경일등 파일의 상태나 정보를 얻는 함수.
 - symbolic link인 파일을 path 로 넘기면 그 원본 파일의 정보를 얻는다. lstat 함수는 symbolic link 파일 자신의 정보를 얻는다.
 - *path인자는 파일명 또는 파일에 대한 상대/절대 경로, buf인자는 파일의 상태 및 정보를 저장할 buf 구조체이다.
 - 구조체 정보 : https://www.it-note.kr/173
 - 성공시 0, 실패시 -1 리턴, errno에 저장한다.

### lstat
```
#include <sys/stat.h>
int lstat(const char *path, struct stat * buf)
```
 - stat함수와 동작하는 기능이 같다.
 - symbolic link인 파일을 path로 넘기면 symbolic link인 파일 자체의 정보를 얻는다.

### fstat
```
#include <sys/stat.h>
int fstat(int fd, struct stat *buf)
```
 - 열려진 파일의 크기, 파일의 권한, 파일의 생성일시, 최종 변경일 등 파일의 상태나 파일의 정보를 얻는 함수.
 - 인자 fd는 `open`등으로 생성한 파일 디스크럽터이다.
