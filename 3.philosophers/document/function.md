### 사용 함수들

##### usleep
```
#include <unistd.h>
void usleep(unsigned long usec);
```
 - usec마이크로초동안 호출 프로세스의 실행을 일시 중지한다.

##### gettimeofday
```
#include <sys/time.h>
int gettimeofday(struct timeval *restrict tv, struct timezone *restrict tz);
```
 - 1970-01-01 00:00:00 +0000(UTC)이후의 현재까지의 경과된 초와 마이크로초 값을 얻을 수 있다.
 - tv
    - 1970-01-01 00:00:00 +0000 (UTC) 이후 경과된 초(seconds)와 micro초를 저장할 buffer
    - struct timeval는 아래와 같다.
```
struct timeval {
   time_t      tv_sec;     /* seconds */
   suseconds_t tv_usec;    /* microseconds */
};
```
 - tz
    - timezone 정보로 값은 무시되며, NULL을 사용함.
    - struct timezone는 아래와 같다. (사용하지 않음)
```
struct timezone {
   int tz_minuteswest;     /* minutes west of Greenwich */
   int tz_dsttime;         /* type of DST correction */
};
```

#### pthread

 - pthread란 POSIX Thread의 약자로 유닉스계열의 POSIX시스템에서 병렬적으로 작동하는 소프트웨어를 작성하기 위해 제공하는 API이다.

##### pthread_create
 - 참고 : https://bitsoul.tistory.com/157
```
#include <pthread.h>
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```
 - 쓰레드를 생성한다.
 - 첫번째 매개변수인 thread 는 쓰레드가 성공적으로 생성되었을때 생성된 쓰레드를 식별하기 위해서 사용되는 쓰레드 식별자이다.
 - 두번째 매개변수인 attr 은 쓰레드 특성을 지정하기 위해서 사용하며, 기본 쓰레드 특성을 이용하고자 할경우에 NULL 을 사용한다.
 - 세번째 매개변수인 start_routine는 분기시켜서 실행할 쓰레드 함수이며,
 - 네번째 매개변수인 arg는 위 start_routine 쓰레드 함수의 매개변수로 넘겨진다.
 - 성공적으로 생성될경우 0을 리턴한다.

##### pthread_detach
 - 참고 : https://bitsoul.tistory.com/161
```
#include <pthread.h>
int pthread_detach(pthread_t th);
```
 - 특정 쓰레드를 분리시킨다.
 - 일반적으로 쓰레드를 pthread_create()를 사용하여 생성하면 쓰레드가 종료되어도 사용했던 모든 자원이 해제되지 않는다.
 - 반면 pthread_join()을 사용하여 종료될때까지 기다렸다가 종료시점이 되면 자원이 반납된다.
 - 하지만 pthread_detach()함수는 pthread_join()을 사용하지 않더라도, 쓰레드가 종료될 때 모든 자원을 해제한다.
 - 첫 번째 매개변수 th는 분리시킬 쓰레드의 식별자이다.
 - 성공적으로 실행될 경우 0을, 실패하면 에러코드를 반환한다.

##### pthread_join
 - 참고 : https://bitsoul.tistory.com/160
```
#include <pthread.h>
int pthread_join(pthread_t th, void **thread_return);
```
 - 특정 쓰레드가 종료하기를 기다렸다가 쓰레드가 종료된 이후 다음을 진행한다.
 - 첫 번째 매개변수 th는 기다릴 쓰레드의 식별자이다.
 - 두 번째 매개변수 thread_return은 쓰레드의 리턴값. thread_return값이 NULL이 아닌 경우 해당 포인터로 쓰레드의 리턴 값을 받아올 수 있다.
 - join된(종료된) 쓰레드는 모든 자원을 반납하게 된다.
 - 성공시 0을, 실패시 에러코드를 반환한다.

##### pthread_mutex

 - 참조 : https://dokhakdubini.tistory.com/466
 - 참조 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=redki777&logNo=80144161723
 - 쓰레드에서 가장 중요한 이슈는 race condition이다. 이는 동일한 메모리에 접근할 때, 그 메모리에 대해서 일관성이 유지될 수 있는가에 대한 문제이다.
 - 이러한 문제를 해결하기 위해 대표적으로 사용할 수 있는 함수가 pthread_mutex이다.
 - 사용법은 다음과 같다
```
#include <pthread.h>

pthread_mutex_t fastmutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t recmutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
pthread_mutex_t errchkmutex = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
int phtread_mutex_lock(pthread_mutex_t *mutex);
int phtread_mutex_trylock(pthread_mutex_t *mutex);
int phtread_mutex_unlock(pthread_mutex_t *mutex);
int phtread_mutex_destroy(pthread_mutex_t *mutex);
```
 - 뮤텍스는 MUTual EXclusion(상호 배제)의 약자로 공유된 자료 구조를 동시에 수정하는 것을 방지하고 임계 영역과 모니터를 구현하는 장치이다.
 - 뮤텍스는 다음과 같은 두 가지 상태 값을 가질 수 있다.
   - unlocked : 어떠한 쓰레드도 뮤텍스를 소유하지 않음
   - locked : 한 스레드가 뮤텍스를 소유하고 있음
 - 하나의 뮤텍스는 서로 다른 두 쓰레드가 동시에 소유할 수 없다. 이미 locked상태에 있는 뮤텍스에 다른 쓰레드가 lock을 걸려고 시도하면 일단 뮤텍스가 unlocked상태가 될 때까지 해당 쓰레드는 중지된다.
 - `pthread_mutex_init`은 변수 mutex가 가리키는 뮤텍스 객레츨 mutexattr에 지정된 뮤텍스 속성에 따라 초기화한다. 만약 mutexattr인수가 NULL이면 기본 속성값이 대신 사용된다.
 - LinuxThread의 구현에서는 오직 mutex kind의 뮤텍스 속성만을 지원하며 이것은 fast, recursive, error checking 중의 하나의 값을 가진다. 뮤텍스의 종류는 이미 뮤텍스를 소유하고 있는 쓰레드가 다시 해당 뮤텍스에 lock을 걸려고 하는 경우에 대한 처리를 결정한다. 자세한 정보는 man pthread_mutexattr_init(3) 참조
 - `pthread_mutex_lock`은 주어진 뮤텍스에 lock을 건다. 만약 뮤텍스가 unlocked상태이면 locked상태로 변경되며 호출한 쓰레드가 이 뮤텍스의 소유자가 되고, `pthread_mutex_lock`은 즉시 반환된다. 만일 뮤텍스가 다른 쓰레드에 의해 이미 locked상태이면 `pthread_mutex_lock`은 뮤텍스가 다시 unlocked상태가 될 때까지 호출한 쓰레드를 중지시킨다.
 - `pthread_mutex_unlock`은 주어진 뮤텍스를 unlock한다. 뮤텍스는 호출한 쓰레드가 `pthread_mutex_unlock`을 통해 소유하고 있는 상태라고 가정한다. 만일 뮤텍스가 fast뮤텍스이면 해당 뮤텍스를 unlock상태로 만든다.
 - `pthread_mutex_destroy`는 뮤텍스 객체를 제거하고 객체가 소유한 자원을 해제한다. 이 함수가 수행할 때 뮤텍스는 반드시 unlock상태여야 한다.
