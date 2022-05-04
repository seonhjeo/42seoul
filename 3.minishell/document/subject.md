### Mandatory part

 - Program name : minishell
 - Turn in files :
 - Makefile : Yes
 - Arguments :
 - External functs.
   - readline, rl_on_new_line, rl_replace_line,
   - rl_redisplay, add_history, printf, malloc, free,
   - write, open, read, close, fork, wait, waitpid,
   - wait3, wait4, signal, kill, exit, getcwd, chdir,
   - stat, lstat, fstat, unlink, execve, dup, dup2,
   - pipe, opendir, readdir, closedir, strerror, errno,
   - isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr,
   - tcgetattr, tgetent, tgetflag, tgetnum, tgetstr,
   - tgoto, tputs
 - Libft authorized :  Yes
 - Description : Write a shell

##### Description

당신의 프로그램은 다음과 같은 명령을 수행해야 한다.
 - 닫히지 않은 따옴표나 \혹은 ;와 같이 정의되지 않은 특수문자를 해석하면 안 된다.
 - 하나 이상의 전역 변수를 사용하지 말고, 그것에 대해 생각하고 왜 그것을 하는지를 설명할 준비를 해라.
 - 새 커맨드를 기다리는 동안 프롬프트를 보여라.
 - 작업 히스토리를 갖고 있어라.
 - PATH 변수 기준 혹은 상대경로나 절대경로에 기반한 올바른 실행파일을 찾고 실행해라.
 - 다음과 같은 빌트인을 구현하라:
   - 옵션 `-n`이 포함된 `echo` (`echo -n`은 개행 없는 출력)
   - 상대경로와 절대경로만을 다루는 `cd`
   - 아무 옵션이 없는 `pwd`
   - 아무 옵션이 없는 `export`
   - 아무 옵션이 없는 `unset`
   - 아무 옵션 혹은 인자가 없는 `env`
   - 아무 옵션이 없는 `exit`
 - '는 일련의 문자에 대한 모든 해석을 금지한다.
 - "는 $를 제외한 일련의 문자에 대한 모든 해석을 금지한다.
 - 리디렉션은 다음과 같다.
   - `<`는 입력값을 리디렉트한다.
   - `>`는 출력값을 리디렉트한다.
   - `<<`는 구분 기호만 포함하는 줄이 보일 때까지 현재 소스의 입력을 읽는다. 기록은 업데이트할 필요가 없다.
   - `>>`는 추가(append)모드로 출력을 리디렉션해야 한다.
 - `Pipes |` 파이프라인에 있는 각 명령의 출력은 파이프를 통해 다음 명령의 입력에 연결된다.
 - 환경 변수($ 뒤에 문자가 오는 값)는 값으로 확장되어야 한다.
 - `$?`는 가장 최근에 실행된 포그라운드 파이프라인의 종료 상태로 확장되어야 한다.
 - `ctrl-C ctrl-D ctrl-\` 는 배쉬에서 작동하는 것처럼 작동해야 한다.
 - 인터랙티브의 경우
   - `ctrl-C`는 개행에 새 프롬프르틀 출력한다.
   - `ctrl-D`는 쉘을 탈출한다.
   - `ctrl-\`는 아무것도 하지 않는다.
 - 요구되지 않은 다른 것들은 필요하지 않다.
 - 어떠한 점에서든 의문이 생기면 레퍼런스를 보아라
   - 링크 : https://www.gnu.org/savannah-checkouts/gnu/bash/manual/
