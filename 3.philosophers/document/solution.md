### 솔루션

 - 참조 : https://www.youtube.com/watch?v=YAP0Bv_aQl8
 - 철학자들 문제를 해결하기 위한 3가지 요소는 상호 배제, 데드락 해결, 기아 해결이다.

#### 상호 배제 (Semaphore Solution)

 - 세마포어, 혹은 뮤텍스를 이용해 간단하게 해결 가능하다.
 - 각각의 젓가락에 세마포어(뮤텍스)를 설정해 사용되고 있는 젓가락에는 다른 철학자들의 접근을 방지한다.
 - 다만 단순한 세마포어 해결법은 데드락을 발생시킨다.
 - 세마포어를 이용한 상호 배제는 다음과 같다.
```
semaphore chopstick[5];

while (true)
{
	wait(chopstick[i]);
	wait(chopstick[(i + 1) % 5]);

	/* eat for a while */

	signal(chopstick[i]);
	signal(chopstick[(i + 1) % 5]);

	/* think for a while */
}
```

#### 데드락 (Deadlock)

 - 만일 모든 철학자들이 배가 고프다고 가정하자. 그들 모두가 자신의 왼쪽에 있는 젓가락을 집었고 오른쪽의 젓가락을 집으려 할 때 데드락 상황이 발생한다.
 - 데드락 문제를 해결하는 방법들은 다음과 같다.
   - 철학자를 한 명 없앤다. 그러면 두 명이 한 개의 젓가락에 항상 접근할 수 있어 데드락 상태가 될 수 없다.
   - 철학자들이 두 젓가락이 사용 가능할 때만 젓가락은 잡는다는 등 젓가락을 잡을 수 있는 규정을 만든다.
   - 비대칭 해결법(asymmetric solution)을 사용한다.
     - 홀수 번의 철학자들은 왼쪽의 젓가락을 먼저 잡고 이후에 오른쪽의 젓가락을 잡는다.
     - 반면 짝수 번의 철학자들은 오른쪽의 젓가락을 먼저 잡고 이후에 왼쪽의 젓가락을 잡는다.
 - 위의 여러 방법들을 이용하면 데드락 문제를 해결할 수는 있지만, 기아(starvation)문제는 해결할 수 없다.


##### 모니터 솔루션 (Monitor Solution)

 - 위의 데드락 문제를 해결하는 방법 중 하나이다.
 - 철학자들이 양쪽의 젓가락이 모두 사용 가능할 때만 젓가락은 잡을 수 있게 해보자.
 - 우리는 철학자들의 세 가지 상태(생각, 배고픔, 먹기)를 구별할 필요가 있다.
 - 또한 우리는 철학자들의 상태 변수가 필요하다. 예를 들면
   - 철학자는 양 옆의 철학자가 먹는 상태가 아니일 때(양쪽의 젓가락이 사용 가능할 때)에만 먹기를 허용해준다.
   - 먹은 이후 생각 상태가 되면 젓가락을 놓아준다.
 - 젓가락의 분배는 모니터에 의해 컨트롤된다.
 - 각각의 철학자는 젓가락을 드는 `pickup()`함수를 호출해야 한다. 함수가 성공하면 먹기 상태에 돌입하고, 실패하면 기다린다.
 - `pickup()`함수가 성공한 철학자가 식사를 끝내면 `putdown()`함수를 호출한다.
 - 위는 상호 배제(mutual exclusion)이 보장되어 데드락은 해결할 수 있으나 기아(starvation)문제는 완전히 해결하지 못한다.
```
monitor DiningPhilosophers
{
	enum {THINKING, HUNGRY, EATING} state[5];
	condition self[5];

	void pickup(int i)
	{
		state[i] = HUNGRY;
		test(i);
		if (state[i] != EATING)
			self[i].wait();
	}

	void putdown(int i)
	{
		state[i] = THINKING;
		test((i + 4) % 5);
		test((i + 1) % 5);
	}

	void test(int i)
	{
		if ((state[(i + 4 % 5)] != EATING) &&
			(state[(i + 1 % 5)] != EATING) &&
			state[i] == HUNGRY)
		{
			state[i] = EATING;
			self[i].signal();
		}
	}

	initialization_code()
	{
		for (int i = 0; i < 5; i++)
			state[i] = THINKING;
	}
}
```
