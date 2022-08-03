# 문법
```
":" + <server_name> + " " + <numeric_replies> + " " + <target client nickname> + " " + <message> + "\n"
```
 - server_name : 임의로 지정한 서버 이름
 - numeric_replies : 각 응답마다의 고유번호, RFC의 명령어 파트에 지정되어 있음
   - (RFC에 정의되어 있지 않은 응답을 출력하고 싶으면 일괄 999번으로 통일해서 출력)
 - target client nickname : 메시지를 전송할 클라이언트의 닉네임, 닉네임이 비어있으면 `*`으로 대체
 - message : 메시지
 - https://defs.ircdocs.horse/defs/numerics.html

# 명령어 응답 종류

## ERR_NOTREGISTERED
 - 고유번호 : 451
 - 메시지 양식 : `:You have not registered`
 - 클라이언트가 PASS로 연결을 하지 않았을 시

## 첫 진입 시
 - 클라이언트가 PASS, NICK, USER로 인증과 프로필 세팅을 끝마친 후에 출력해준다

#### RPL_WELCOME
 - 고유번호 : 001
 - 메시지 양식 : `Welcome to the Internet Relay Network\n<nick>!<user>@<host>`

#### RPL_YOURHOST
 - 고유번호 : 002
 - 메시지 양식 : `Your host is <servername>, running version <ver>`

#### RPL_CREATED
 - 고유번호 : 003
 - 메시지 양식 : `This server was created <date>`

#### RPL_MYINFO
 - 고유번호 : 004
 - 메시지 양식 : `<servername> <version> <available user modes>\n<available channel modes>`

## PASS

#### ERR_NEEDMOREPARAMS
 - 고유번호 : 461
 - 메시지 양식 : `PASS :Not enough parameters`
 - PASS 커맨드에 파라미터가 부족할 때 출력

#### ERR_ALREADYREGISTRED
 - 고유번호 : 462
 - 메시지 양식 : `:Unauthorized command (already registered)`
 - 이미 인증한 유저가 또 PASS 커맨드를 사용할 때 출력


## NICK

#### ERR_NONICKNAMEGIVEN
 - 고유번호 : 431
 - 메시지 양식 : `:No nickname given`
 - NICK 커맨드에 닉네임을 입력받지 못했을 때 출력

#### ERR_ERRONEUSNICKNAME
 - 고유번호 : 432
 - 메시지 양식 : `<nickname> :Erroneous nickname`
 - 입력받은 닉네임이 서버의 닉네임 정의에 부합하지 않을 때 출력

#### ERR_NICKNAMEINUSE 
 - 고유번호 : 433
 - 메시지 양식 : `<nick> :Nickname is already in use`
 - 입력받은 닉네임을 이미 다른 사람이 사용중일 때 출력

#### ERR_NICKCOLLISION (not used)
 - 고유번호 : 436
 - 메시지 양식 : `<nick> :Nickname collision KILL from <user>@<host>`
 - 입력받은 닉네임이 다른 서버에서 이미 사용중일 때 출력

#### ERR_UNAVAILRESOURCE (not used)
 - 고유번호 : 437
 - 메시지 양식 : `<nick/channel> :Nick/channel is temporarily unavailable`
 - 클라이언트가 서버에 접속하려 하는 상황에서 서버가 딜레이로 인해 잠시동안 유저의 명령을 블락할 때 출력

#### ERR_RESTRICTED (not useed)
 - 고유번호 : 484
 - 메시지 양식 : `":Your connection is restricted!"`
 - 서버가 클라이언트의 접근을 제한시킨 상태에서 클라이언트가 서버에 접속하려 할 때


## USER

#### ERR_NEEDMOREPARAMS
 - 고유번호 : 461
 - 메시지 양식 : `USER :Not enough parameters`
 - USER 커맨드에 파라미터가 부족할 때 출력

#### ERR_ALREADYREGISTRED
 - 고유번호 : 462
 - 메시지 양식 : `:Unauthorized command (already registered)`
 - 이미 유저 설정을 한 유저가 또 하려고 할 때 출력


## JOIN

#### ERR_NEEDMOREPARAMS
 - 고유번호 : 461
 - 메시지 양식 : `JOIN :Not enough parameters`
 - JOIN 커맨드에 파라미터가 부족할 때 출력

#### ERR_BANNEDFROMCHAN (not used)
 - 고유번호 : 474
 - 메시지 양식 : `<channel> :Cannot join channel (+b)`
 - 채널이 밴한 클라이언트가 채널에 입장하려 할 때 출력

#### ERR_INVITEONLYCHAN (not used)
 - 고유번호 : 473
 - 메시지 양식 : `<channel> :Cannot join channel (+i)`
 - 비공개 채널에 클라이언트가 입장하려 할 때 출력

#### ERR_BADCHANNELKEY
 - 고유번호 : 475
 - 메시지 양식 : `<channel> :Cannot join channel (+k)`
 - 클라이언트가 입력한 비밀번호가 맞지 않을 때 출력

#### ERR_CHANNELISFULL
 - 고유번호 : 471
 - 메시지 양식 : `<channel> :Cannot join channel (+l)`
 - 클라이언트가 접속하려 하는 채널이 꽉 차 있을 때 출력

#### ERR_BADCHANMASK (not used)
 - 고유번호 : 476
 - 메시지 양식 : `<channel> :Bad Channel Mask`
 - ????

#### ERR_NOSUCHCHANNEL
 - 고유번호 : 403
 - 메시지 양식 : `<channel name> :No such channel`
 - 인자로 받은 채널이 존재하지 않을 때 출력

#### ERR_TOOMANYCHANNELS
 - 고유번호 : 405
 - 메시지 양식 : `<channel name> :You have joined too many channels`
 - 하나의 클라이언트가 입장할 수 있는 채널의 양을 초과하여 채널에 입장하려 할 때 출력

#### ERR_TOOMANYTARGETS (not used)
 - 고유번호 : 407
 - 메시지 양식 : `<target> :<error code> recipients. <abort message>`
 - 입장하려 하는 서버가 중복된 이름이 많을 때 출력

#### ERR_UNAVAILRESOURCE (not used)
 - 고유번호 : 437
 - 메시지 양식 : `<channel> :Channel is temporarily unavailable`
 - 현재 입장하려는 채널이 한시적으로 사용 불가능할 때 출력

#### RPL_TOPIC
 - 고유번호 : 332
 - 메시지 양식 : `<channel> :<topic>`
 - 클라이언트가 채널에 성공적으로 접속하면 출력, 토픽이 없으면 RPL_NOTOPIC 메시지 출력

#### RPL_NOTOPIC
 - 고유번호 : 331
 - 메시지 양식 : `<channel> :No topic is set`


## KICK

#### ERR_NEEDMOREPARAMS
 - 고유번호 : 461
 - 메시지 양식 : `KICK :Not enough parameters`
 - 파라미터가 부족할 때 출력

#### ERR_NOSUCHCHANNEL
 - 고유번호 : 403
 - 메시지 양식 : `<channel name> :No such channel`
 - 타겟 채널이 없을 때 출력

#### ERR_BADCHANMASK (not used)
 - 고유번호 : 476
 - 메시지 양식 : `<channel> :Bad Channel Mask`

#### ERR_CHANOPRIVSNEEDED
 - 고유번호 : 482
 - 메시지 양식 : `<channel> :You're not channel operator`
 - 채널 오퍼레이터가 아닌 사람이 킥을 하려고 할 때 출력
#### ERR_USERNOTINCHANNEL
 - 고유번호 : 441
 - 메시지 양식 : `<nick> <channel> :They aren't on that channel`
 - 타겟이 채널에 없을 때 출력

#### ERR_NOTONCHANNEL
 - 고유번호 442
 - 메시지 양식 : `<channel> :You're not on that channel`
 - 현재 채널에 없을 때 출력

## PRIVMSG

#### ERR_NORECIPIENT
 - 고유번호 : 411
 - 메시지 양식 : `:No recipient given (PRIVMSG)`
 - 메시지 전송 대상이 입력되지 않았을 때 출력

#### ERR_NOTEXTTOSEND
 - 고유번호 : 412
 - 메시지 양식 : `:No text to send`
 - 메시지가 입력되지 않았을 때 출력

#### ERR_NOTOPLEVEL (not used)
 - 고유번호 : 413
 - 메시지 양식 : `<mask> :No toplevel domain specified`
 - `PRIVMSG $<server>` 시도가 실패했을 때 출력

#### ERR_WILDTOPLEVEL (not used)
 - 고유번호 : 414
 - 메시지 양식 : `<mask> :Wildcard in toplevel domain`
 - `PRIVMSG #<host>` 시도가 실패했을 때 출력

#### ERR_CANNOTSENDTOCHAN
 - 고유번호 : 404
 - 메시지 양식 : `<channel name> :Cannot send to channel`
 - 유저가 채널에 속해있지 않거나 밴 당했지만 해당 채널에 메시지를 전송하려 한 경우 출력

#### ERR_TOOMANYTARGETS (not used)
 - 고유번호 407
 - 메시지 양식 : `<target> :<error code> recipients. <abort message>`
 - 유저가 너무 많은 개별 클라이언트에게 메시지를 전송하려 할 때 출력

#### ERR_NOSUCHNICK
 - 고유번호 : 401
 - 메시지 양식 : `<nickname> :No such nick/channel`
 - 입력받은 닉네임이 존재하지 않을 때 출력

#### RPL_AWAY (not used)
 - 고유번호 : 301
 - 메시지 양식 : `<nick> :<away message>`
 - 전송 대상이 away상태일 때 출력


## PART
 
#### ERR_NEEDMOREPARAMS
 - 고유번호 : 461
 - 메시지 양식 : `PART :Not enough parameters`
 - PART 명령어의 파라미터가 부족할 때 출력

#### ERR_NOSUCHCHANNEL (not used)
 - 고유번호 : 403
 - 메시지 양식 : `<channel name> :No such channel`
 - 해당하는 채널이 서버에 존재하지 않을 때 출력

#### ERR_NOTONCHANNEL
 - 고유번호 : 442
 - 메시지 양식 : `<channel> :You're not on that channel`
 - 클라이언트가 해당 채널의 멤버가 아니지만 채널에 영향을 끼치는 명령어를 실행할 때 출력


## LIST

#### ERR_TOOMANYMATCHES (not used)

#### ERR_NOSUCHSERVER (not used)
 - 고유번호 : 402
 - 메시지 양식 : `<server name> :No such server`
 - 해당 서버가 존재하지 않을 때 출력

#### RPL_LIST
 - 고유번호 : 322
 - 메시지 양식 : `<channel> <# visible> :<topic>`
 - 출력되는 리스트들의 몸통 부분

#### RPL_LISTEND
 - 고유번호 : 323
 - 메시지 양식 : `:End of LIST`
 - 출력되는 리스트들의 꼬리 부분


## ISON

#### RPL_ISON
 - 고유번호 : 303
 - 메시지 양식 : `:*1<nick>`
 - ISON으로 유저를 찾았을 때 출력

#### ERR_NEEDMOREPARAMS
 - 고유번호 : 461
 - 메시지 양식 : `ISON :Not enough parameters`
 - ISON 명령어의 파라미터가 부족할 때 출력


## QUIT

#### 메시지 없음


## PING & PONG

#### RFC2812에는 서버간 연결에 대한 명령임