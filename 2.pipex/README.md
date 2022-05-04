### 목표

* './pipex file1 cmd1 cmd2 file2'가 쉘의 '< file1 cmd1 | cmd2 > file2'와 같은 동작을 취해야 한다.
* '< file1 cmd1 | cmd2 > file2'는 file1의 내용을 이용해 cmd1을 수행하여 나온 결과를 cmd2를 다시 수행하여 file2에 저장하는 것이다.


### 해결 방법

* pipex 프로그램은 cmd1과 cmd2 두 가지의 프로세스를 동시에 실행해야 한다.
* pipex 프로그램은 file1의 내용을 읽어 cmd1에 전송하고, cmd2의 내용을 file2에 작성해야 한다.
* pipex 프로그램은 cmd1이 처리한 결과를 cmd2에 입력으로 제공해야 한다.
* 리눅스 명령어 참조 : https://zzsza.github.io/development/2017/12/04/linux-1/


### 사전 지식

#### main함수의 환경 변수
* main함수의 입력 매개변수는 총 3개가 있다.
* 각각 argc(명령행 인자 개수), argv(명령행 인자 벡터), envp(환경 변수 목록)이다.
* 참조 : https://ehpub.co.kr/tag/environ-%EB%B3%80%EC%88%98/


### 사용하는 함수

#### access
* 형식 : int access(const char *path, int mode);
* path 경로에 존재하는 파일의 유무와 접근 권한을 파악하는 함수이다. 파악하는 범위는 mode변수를 이용해 제어한다.
* mode 변수는 읽기 권한의 R_OK, 쓰기 권한인 W_OK, 실행/탐색 권한인 X_OK, 존재 유무 파악인 F_OK가 있다.
* 함수의 실행이 성공하면 0을, 에러가 발생하면 -1을 반환한다.

#### unlink
* 형식 : int unlink(const char *path);
* path 경로에 존재하는 파일을 삭제한다. 파일을 삭제한다는 것은 디렉토리 파일에서 그 파일의 엔트리를 삭제한다는 뜻이다.
* 비슷한 행동을 하는 remove함수는 삭제 대상이 디렉토리이면 rmdir과 동일한 행동을 취한다.

#### wait
* 형식 : pid_t wait(int *status)
* 자식 프로세스의 작업이 끝날 때까지 대기한 후 자식 프로세스가 종료한 상태를 구한다.
* 자식 프로세스가 정상 종료되었다면 status변수의 상위 8비트에 반환값을, 비정상 종료되었다면 하위 8비트에 반환값을 저장한다.
* 참조 : http://forum.falinux.com/zbxe/index.php?document_srl=408545&mid=C_LIB

#### waitpid
* 형식 : pid_t waitpid(pit_t pid, int *statloc, int options);
* wait함수처럼 자식 프로세스를 기다릴 때 사용하는 함수이다. 즉, 자식 프로세스의 종료상태를 회수할 때 사용한다.
* waitpid함수는 wait함수와는 다르게 자식 프로세스가 종료될 때까지 차단되는 것을 원하지 않는 경우 옵션으로 차단을 방지할 수 있다.
* 참조 : https://codetravel.tistory.com/42

#### fork
* 형식 : pid_t fork(void);
* 프로세서를 생성하고자 할 때 사용한다.
* fork함수를 호출하는 프로세스는 부모 프로세스, 새롭게 생성되는 프로세스는 자식 프로세스가 된다.
* fork함수에 의해 생성된 자식 프로세스는 부모 프로세스의 메모리를 그대로 복사하여 가지게 된다.
* 성공시 부모 프로세스는 자식 프로세스의 PID값을, 자식 프로세스는 0을 반환받고, 실패시 부모 프로세스는 -1을 반환받는다.
* 참조 : https://codetravel.tistory.com/23
* 참조 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=qo9895&logNo=221239427517

#### pipe
* 형식 : int pipe(int fd[2]);
* 프로세스간 통신을 할 때 사용하는 커뮤니케이션의 한 방법.
* 반이중 방식이며, 부모자식간의 관계에서만 사용 가능하다. 반이중 방식은 FIFO를 이용해 극복이 가능하다.
* 파이프는 커널 영역에서 생성되며 프로세스에서 fd[1]을 이용해 쓰기를, fd[0]을 이용해 읽기를 시행할 수 있다.
* fork()함수를 이용해 연결된 부모자식 프로세스에서 부모 프로세스가 fd[1]을 이용해 파이프에 쓴 후 fd[0]으로 자식 프로세스에 읽힐 수 있다.
* 참조 : https://reakwon.tistory.com/80

#### dup, dup2
* 형식 : int dup(int fd);  /  int dup2(int fd, int fd2);
* 두 함수 모두 파일 디스크립터를 복사하는 함수이다.
* dup는 fd로 전달받은 파일 서술자를 반환하고, dup2는 새 서술자의 값을 fd2로 저장한다. 만일 fd2가 열려있으면 fd2를 닫은 후에 복제한다.
* 두 함수 모두 성공시 새 파일 서술자를, 오류시 -1을 반환한다.
* 참조 : https://reakwon.tistory.com/104

#### execve
* 형식 : int execve(const char *filename, char *const argv[], char *const envp[]);
* filename이 가리키니는 파일을 실행한다. 이 때 이 파일은 바이너리 실행파일이거나 스크립트 파일이어야만 한다.
* argv[]는 파일 인자의 포인터를, envp[]는 환경변수의 포인터를 가리킨다.
* 참조 : https://watchout31337.tistory.com/136
* 참조 : https://www.it-note.kr/157
