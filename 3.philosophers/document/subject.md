### Mandatory description

당신은 필수 파트와 보너스 파트에서 각각 하나의 프로그램을 작성해야 합니다. 하지만 이들은 동일한 기본 규칙을 지닙니다:
 - 이 프로그램은 C로 코딩되며 놈을 따라야 합니다. 어떠한 누수, 충돌, 비정의된 행동, 놈 에러는 0점입니다.
 - 하나 이상의 철학자들이 원형 탁자에 앉아 세 가지 일 중 하나를 합니다: 먹기, 생각하기, 잠자기입니다.
 - 그들이 먹는 도중에는 생각이나 잠자기를 못합니다. 자는 도중에는 먹기나 생각하기를 못하고, 당연하게도 생각하는 도중에는 먹거나 잠자기를 못합니다.
 - 철학자들은 가운데에 큰 스파게티 접시가 있는 원형 탁자에 앉아있습니다.
 - 테이블 위에는 몇몇 포크들이 놓여 있습니다.
 - 스파게티는 한 개의 포크로 갖고와 먹기에는 어렵기 때문에 철학자는 스파게티를 각각 한 손에 두 개씩 들어 먹어야합니다.
 - 철학자들은 배고파지면 안 됩니다.
 - 모든 철학자들은 먹어야 합니다.
 - 철학자들은 서로 말을 하지 않습니다.
 - 철학자들은 언제 다른 철학자들이 죽는지 모릅니다.
 - 철학자가 먹는 것을 끝내면 그는 포크를 내려놓고 잠자기 시작합니다.
 - 철학자가 잠을 다 자면 생각하기 시작합니다.
 - 철학자가 죽으면 시뮬레이션은 끝납니다.
 - 각각 프로그램은 똑같은 옵션을 가져야 합니다: 철학자들의_숫자 / 죽을_시간 / 먹을_시간 / 잠잘_시간 / [각각의_철학자들이_꼭_먹어야_되는_양]
   - 철학자들의_숫자 : 철학자들의 숫자이자 포크의 개수입니다.
   - 죽을_시간 : 밀리초 단위로, 시뮬레이션의 시작 혹은 철학자의 마지막 식사로부터 죽을_시간동안 식사를 시작하지 않았으면 철학자는 죽습니다.
   - 먹을_시간 : 밀리초 단위로, 철학자들이 먹는 데 걸리는 시간입니다. 그 시간동안 철학자는 두 개의 포크를 갖고 있어야 합니다.
   - 잠잘_시간 : 밀리초 단위로, 철학자들이 잠자는 시간입니다.
   - 각각의_철학자들이_꼭_먹어야_되는_양 : 선택적인 인자로, 모든 철학자들이 최소 해당 인자만큼 식사를 하였으면 시뮬레이션을 종료시킵니다. 해당 인자가 정의되지 않았으면 철학자들이 죽었을 때에만 시뮬레이션을 종료합니다.
 - 각각의 철학자들은 1부터 철학자들의_숫자 까지의 번호를 부여받습니다.
 - 철학자 1번은 철학자 철학자들의_숫자 번호 옆에 있습니다. 철학자 n번은 철학자 n-1번과 철학자 n+1번 사이에 있습니다.
 - 어떤 상태 변경이든 철학자는 다음과 같이작성되야 합니다.(X는 철학자의 번호로, timestamp_in_ms는 현재 타임스탬프를 밀리초 단위로 작성해야 합니다.)
   - timestamp_in_ms X has taken a fork
   - timestamp_in_ms X is eating
   - timestamp_in_ms X is sleeping
   - timestamp_in_ms X is thinking
   - timestamp_in_ms X died
 - 상태 출력은 다른 철학자의 상태와 혼동되거나 뒤엉켜서는 안 됩니다.
 - 당신은 철학자의 죽음과 그 죽음의 출력 사이에 10밀리초 이상을 소비해서는 안 됩니다.
 - 마지막으로 철학자들은 죽음을 피해야 합니다.

### Mandatory part

Program name :  philo
Turn in files :  philo/
Makefile : Yes
Arguments : number_of_philosophers time_to_die time_to_eat
time_to_sleep [number_of_times_each_philosopher_must_eat]
External functs : memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
Libft authorized : No
Description : philosopher with threads and mutex
해당 버전에서의 특수 규칙
 - 하나의 포크는 철학자들의 사이에, 즉 다수의 철학자들이 존재하면, 철학자들의 좌우에 각각 하나씩의 포크가 있어야 함.
 - 철학자들이 포크를 복사하는 것을 방지하기 위해, 각각의 포크의 상태를 뮤텍스로 보호해야 한다.
 - 각각의 철학자들은 쓰레드여야 한다.

### Bonus part

Program name : philo_bonus
Turn in files : philo_bonus/
Makefile : Yes
Arguments : number_of_philosophers time_to_die time_to_eat
time_to_sleep [number_of_times_each_philosopher_must_eat]
External functs. : memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink
Libft authorized : No
Description : philosopher with processes and semaphore
해당 버전에서의 특수 규칙
 - 모든 포크들은 테이블의 중앙에 있다.
 - 그들은 메모리에 어떠한 상태도 없지만, 세마포어에 사용가능한 포크의 양이 표시된다.
 - 각각의 철학자들은 프로세스여야 하고, 메인 프로세스는 철학자이면 안 된다.
