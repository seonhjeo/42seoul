# 07-22 스터디

명령어

HELP, PASS ,KICK, USER, JOIN, PRIVMSG, PART, LIST, ISON, QUIT, PING, PONG

PASS

```c
PASS <password>

NICK / USER 등록 조합전에 전송되어야 합니다.
제공된 암호는 C/N line(서버용)또는 I line(클라이언트용)에 포함된 암호와 일치해야합니다.

등록 전에 여러개의 PASS 명령을 전송할 수 있지만 마지막으로 전송 된 명령만 확인에 사용되며,
등록 후에는 변경할 수 없습니다.
```

KICK

```c
KICK <channel> <client> :[<message>]

채널에서 사용자를 강제로 제거할 수 있습니다.
채널운영자만 다른 사용자를 채널에서 쫒아낼 수 있습니다.
KICK 메세지를 수신하는 서버는 채널에서 피해자를 제거하기전 유효한지 확인합니다
(채널운영자가 작성했는지 확인)

example:
KICK &Melbourne Matthew; 
Kick Matthew from &Melbourne

KICK #Finnish John :Speaking English; 
Kick John from #Finnish using "Speaking English" as the reason(comment).

:WiZ KICK #Finnish John;
KICK message from WiZ to remove John from channel #Finnish

명령매개변수 다음으로 확장 가능
<channel>{,<channel>} <user>{,<user>} [<comment>]
```

USER

```c
USER <user> <mode> <unused> <realname>

이 명령은 연결 시작 시 연결 클라이언트의 사용자 이름, 호스트 이름, 실제 이름
및 사용자 모드를 지정하는 데 사용됩니다.

<realname>은 처음 시작시 ':'을 사용합니다.

<mode>는 숫자여야 하며 서버 등록할 때 사용자모드를 자동 설정하는데 사용합니다.
bit 2는 mode 'w' 이고 bit 3은 mode 'i'가 설정됩니다.

Example:
	USER guest 0 * :Ronnie Reagan; 
	User registering themselves with a username of "guest" and real name "Ronnie Reagan".

  USER guest 8 * :Ronnie Reagan;
	User registering themselves with a username of "guest" and real name "Ronnie Reagan",
	and asking to be set invisible.
```

MODE

```c
MODE <nickname> <flag>
*( "+" / "-" ) *( "i" / "w" / "o" / "O" / "r" )
사용자가 보는 방식또는 클라이언트가 보내는 추가 메세지에 영향을 미치는 변경사항 입니다.
메세지 발신인과 매개변수로 지정된 닉네임이 모두 동일한 경우에만 허용되어야 합니다.

다른 매개변수가 지정되지 않은 경우 서버는 닉에 대한 현재설정을 반환합니다.

a - 사용자는 away로 플래그가 지정됩니다.
i - 사용자를 보이지 않는 것으로 표시합니다.
w - 사용자가 월롭을 수신합니다.
r - 사용자 연결이 제한됩니다.
o - 연산자 플래그;
O - 로컬 연산자 플래그입니다.
s - 사용자에게 서버 통지를 수신하도록 표시합니다.

MODE a를 사용하여 flag 'a'를 전환하면 안되고 AWAY 명령을 사용해야합니다.
사용자가 '+o', '+O'플래그를 사용하여 자신을 operator 만들려고 하면 안됩니다.
그러나 '-o', '-O'를 사용하여 스스로 'deopping'하는 것에 대한 제한은 없습니다.
사용자가 '-r' 사용하여 제한되지 않을려고 하는 것도 무시해야합니다.
그러나 '+r'을 사용하여 직접 'deppoing'하는 것은 제한이 없습니다.
일반적으로 제한된 상태에서 닉네임 변경하거나 채널에서 채널운영자가 될수 없습니다.

MODE WiZ -w;
Command by WiZ to turn off reception of WALLOPS messages.
WALLOPS 메시지 수신을 해제하도록 WiZ에서 명령합니다.

MODE Angel +i;
Command from Angel to make herself invisible.
Angel이 자신을 보이지 않게 하라고 명령합니다.

MODE WiZ -o;
WiZ 'deopping' (removing operatorstatus).
WiZ 'deopping'(오퍼레이터 상태 제거)입니다.
```

JOIN

```c
JOIN <channel>{,<channel>} [<key>{,<key>}]

클라이언트가 특정 채널 수신을 시작하기 위해 사용합니다.

1. 채널이 초대 전용인 경우 사용자를 초대해야 합니다.
2. 사용자의 닉/스킨/호스트명은 활성 금지와 일치하지 않아야 합니다.
3. 설정된 경우 올바른 키(암호)를 제공해야 합니다.

사용자가 채널에 가입하면 서버에 수신되는 모든 명령에 대한
통지를 수신하여 채널에 영향을 미칩니다.

여기에는 MODE, KICK, PART, QUIT 및 물론 PRIBMG/NOTICE가 포함됩니다.

각 서버가 채널에 있는 사용자를 찾을 수 있는 위치를 알 수 있도록 모든 서버에
JOIN 명령을 브로드캐스트해야 합니다.

이를 통해 PRIBMSG/NOTICE 메시지를 채널에 최적으로 전달할 수 있습니다.

JOIN이 성공하면 사용자는 채널의 주제(using RPL_TOPIC)와 채널에 있는 
사용자 목록(using RPL_NAMREPLY)을 보내게 됩니다. 여기에는 사용자 참여가 포함되어야 합니다.

Examples:
  JOIN #foobar;
	join channel #foobar.
	채널 #foobar에 가입

  JOIN &foo fubar;
	join channel &foo using key "fubar".
	키 "fubar" 사용하여 &foo 채널에 연결합니다.

	JOIN #foo,&bar fubar;
	join channel #foo using key "fubar" and &bar using no key.
	키 "fubar" 사용하여 #foo join하고 키없이 &bar에 join한다.
 
  JOIN #foo,#bar fubar,foobar;
	join channel #foo using key "fubar".and channel #bar using key "foobar".
	키 "fubar" 사용하여 #foo join하고 키 "foobar" 사용하여 &bar에 join한다.

  JOIN #foo,#bar;
	join channels #foo and #bar.
	채널 #foo 및 #bar를 연결합니다.

  :WiZ JOIN #Twilight_zone;
	JOIN message from WiZ
	Wiz에서 온 JOIN message
```

PRIVMSG

```c
PRIVMSG <msgtarget> <text to be sent>

PRIBMSG는 사용자 간에 개인 메시지를 보내고 채널에 메시지를 보내는 데 사용됩니다.
<msgtarget>은 일반적으로 메시지 수신인의 닉네임 또는 채널 이름입니다.

<msgtarget> 매개 변수는 호스트 마스크(#mask) 또는 서버 마스크($mask)를 의미할수도 있습니다
두 경우 모든 서버는 PRIVMSG를 마스크와 일치하는 서버 또는 호스트가 있는
사용자에게만 보냅니다.

마스크에는 적어도 1개의 "."가 있어야 하며 마지막 "." 뒤에 와일드카드가 없어야 합니다

이 요구 사항은 모든 사용자에게 브로드캐스트되는 "#*" 또는 "$*"에 메시지를 보내는 것을
방지하기 위해 존재합니다.

와일드카드는 '*' 및 '?' 문자입니다.

이 PRIVMSG 명령 확장 기능은 Operators만사용할 수 있습니다.

예:
:Angel!wings@irc.org PRIVMSG Wiz :Are you receiving this message ?;
Message from Angel to Wiz.
엔젤이 위즈에게 보내는 메시지입니다

PRIVMSG Angel :yes I'm receiving it !;
Command to send a message to Angel.
엔젤에게 메시지를 보낼 명령입니다.

PRIVMSG jto@tolsun.oulu.fi :Hello !;
Command to send a message to a user on server tolsun.oulu.fi with username of "jto".
사용자 이름 "jto"로 tolsun.oulu.fi 서버의 사용자에게 메시지를 보내는 명령입니다.

PRIVMSG kalt%millennium.stealth.net@irc.stealth.net :Are you a frog?;
Message to a user on server irc.stealth.net with username of "kalt", and connected
from the host millennium.stealth.net.
사용자 이름이 "kalt"이고 호스트 millennium.stealth.net에서
연결된 서버 irc.stealth.net의 사용자에게 보내는 메시지입니다.

PRIVMSG kalt%millennium.stealth.net :Do you like cheese?;
Message to a user on the local server with username of "kalt", and
connected from the host millennium.stealth.net.
사용자 이름이 "kalt"이고 호스트 millennium.stealth.net에서
연결된 로컬 서버의 사용자에게 보내는 메시지입니다.

PRIVMSG Wiz!jto@tolsun.oulu.fi :Hello !;
Message to the user with nickname Wiz who is connected from the host
tolsun.oulu.fi and has the username "jto".
호스트 tolsun.oulu.fi에서 연결되어 있고 사용자 이름 "jto"를
가진 별명이 Wiz인 사용자에게 보내는 메시지입니다.

PRIVMSG $*.fi :Server tolsun.oulu.fi rebooting.;
Message to everyone on a server which has a name matching *.fi.
*.fi와 일치하는 이름을 가진 서버의 모든 사용자에게 보내는 메시지입니다.

PRIVMSG #*.edu :NSFNet is undergoing work, expect interruptions;
Message to all users who come from a host which has a name matching *.edu.
이름이 *.edu와 일치하는 호스트에서 온 모든 사용자에게 보내는 메시지입니다.
```

PART

```c
<channel> *( "," <channel> ) [ <Part Message>

PART 메시지는 메시지를 보내는 클라이언트가 매개 변수 문자열에 나열된 모든 지정된 채널의
활성 사용자 목록에서 제거되도록 합니다.

"Part Message"가 지정된 경우 기본 메시지인 닉네임 대신 메시지가 전송됩니다.
서버는 대상 목록 형식의 인수를 구문 분석할 수 있어야 하지만 클라이언트에
부분 메시지를 보낼 때 목록을 사용하면 안 됩니다

PART #twilight_zone;
leave channel "#twilight_zone"
채널 "#message_zone"을 떠납니다.

PART #oz-ops,&group5;
leave both channels "&group5" and "#oz-ops".
두 채널 "&group5"와 "#oz-ops"를 모두 종료합니다.

:WiZ!jto@tolsun.oulu.fi PART #playzone :I lost;
User WiZ leaving channel "#playzone" with the message "I lost".
사용자 WiZ가 "I lost" 메시지와 함께 채널 "#playzone"을 떠납니다.
```

LIST

```c
LIST [ <channel> *( "," <channel> ) [ <target> ] ]

list 명령은 채널과 해당 항목을 나열하는 데 사용됩니다.
<channel> 파라미터를 사용하는 경우 해당 채널의 상태만 표시됩니다.
<target> 매개변수가 지정된 경우, 요청이 해당 서버로 전달되어 응답이 생성됩니다.
<target> 매개 변수에는 와일드카드를 사용할 수 있습니다.

예:
LIST;
Command to list all channels.
모든 채널을 나열하는 명령입니다.

LIST #twilight_zone,#42;
	Command to list channels #twilight_zone and #42
채널 #twilight_zone 및 #42를 나열하는 명령입니다.
```

ISON

```c
ISON <nickname> *( SPACE <nickname> )

ISON 명령은 주어진 닉네임이 현재 IRC에 있는지 여부에 대한 응답을 빠르고 
효율적으로 얻기 위해 구현되었습니다.

ISON은 한 가지 유형의 매개 변수(공백으로 구분된 닉 목록)만 사용합니다
서버는 목록에 있는 각 닉네임에 대해 회신 문자열에 추가합니다.

따라서 응답 문자열이 비어 있거나(지정된 닉이 없음), 매개 변수 문자열의
정확한 복사본(모두 있음) 또는 매개 변수에 지정된 닉 집합의
다른 하위 집합이 반환될 수 있습니다.

확인할 수 있는 닉의 수에 대한 유일한 제한은 서버에서 512자 이내로
자를 수 있을 정도로 너무 길지 않아야 한다는 것입니다.

ISON은 명령어를 보내는 클라이언트에 로컬인 서버에서만 처리되므로
추가 처리를 위해 다른 서버로 전달되지 않습니다.

예:
ISON phone trillian WiZ jarlek Avalon Angel Monstah syrk;
Sample ISON request for 7 nicks.
7닉에 대한 ISON 요청의 샘플입니다.
```

QUIT

```c
QUIT [ <Quit Message> ]

클라이언트 세션이 quit 메시지로 종료됩니다.
서버는 클라이언트에 오류 메시지를 보내 이를 확인합니다.

QUIT :Gone to have lunch;
Preferred message format.
기본 설정 메시지 형식입니다.

:syrk!kalt@millennium.stealth.net QUIT :Gone to have lunch;
User syrk has quit IRC to have lunch.
사용자 syrk가 Gone to have lunch 메세지를 띄우고 IRC를 종료하였습니다
```

PING

```c
PING <server1> [ <server2> ]

PING 명령은 연결의 다른 쪽 끝에 활성 클라이언트 또는 서버가
있는지 테스트하는 데 사용됩니다.
연결에서 발견되는 다른 활동이 없는 경우 서버는 정기적으로 PING 메시지를 발송합니다.
설정된 시간 내에 PING 메시지에 응답하지 못하면 해당 연결이 닫힙니다.
연결이 활성 상태인 경우에도 PING 메시지가 전송될 수 있습니다.
PING 메시지가 수신되면, 적절한 PON 메시지를 가능한 한 빨리
<server1>(PING 메시지를 보낸 서버)에 회신으로 보내야 합니다.
<server2> 매개 변수가 지정된 경우 ping의 대상을 나타내며 메시지가 전달됩니다.

PING tolsun.oulu.fi;
Command to send a PING message to server
PING 메시지를 서버로 보내는 명령입니다.

PING WiZ tolsun.oulu.fi;
Command from WiZ to send a PING message to server "tolsun.oulu.fi"
WiZ에서 PING 메시지를 "tolsun.oulu.fi" 서버로 보내도록 명령합니다.

예:
PING :irc.funet.fi;
Ping message sent by server "irc.funet.fi"
서버 "irc.funet.fi"에서 Ping 메시지를 보냈습니다.
```

PONG

```c
PONG <server> [ <server2> ]

PONG 메시지는 ping 메시지에 대한 회신입니다.
매개 변수 <server2>가 지정된 경우 이 메시지를 지정된 대상으로 전달해야 합니다.
<server> 매개 변수는 PING 메시지에 응답하고 이 메시지를 생성한 엔티티의 이름입니다.

예:
PONG csd.bu.edu tolsun.oulu.fi;
csd.bu.edu에서 tolsun.oulu.fi으로 PONG 메시지를 보냅니다.
```

select, poll, epoll, kqueue 성능차이

[https://monkey.org/~provos/libevent/libevent-benchmark.jpg](https://monkey.org/~provos/libevent/libevent-benchmark.jpg)

[https://velog.io/@makehardtraining/IO-Multiplexingselect-poll-epoll-kqueue](https://velog.io/@makehardtraining/IO-Multiplexingselect-poll-epoll-kqueue)