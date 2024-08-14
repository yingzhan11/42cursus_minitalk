!/bin/zsh

PATH_TO_CLIENT="./client"

###################
# Preparing tests #
###################

for init in t1 t2 t3 t4 pid
do
	export $init=0
done

for i in $@
do
	case $i in
		"-1") t1=1;;
		"-2") t2=1;;
		"-3") t3=1;;
		"-4") t4=1;;
		*) if [[ $pid = 0 ]] ; then pid=$i; else echo "[ERROR] Please enter correct arg when launching."; exit; fi;;
	esac
done

if [[ $t1 == 0 && $t2 == 0 && $t3 == 0 && $t4 == 0 ]]
then
  echo "[ERROR] Please enter test No. [-1~4]"
  exit
fi

###########
# Testing #
###########

### Test 1 ###
if [[ $t1 == 1 ]]
then
	echo "[Test 1.1] Basic test"
	$PATH_TO_CLIENT $pid "Test 1.1: Hello, this is a first test" 
fi

### Test 2 ###
if [[ $t1 == 1 ]]
then
	echo "[Test 1.2] Empty string"
	$PATH_TO_CLIENT $pid ""
fi

### Test 3 ###
if [[ $t1 == 1 ]]
then
	echo "[Test 1.3] Number string"
	$PATH_TO_CLIENT $pid "Test 1.3: 12345678901234567890123456789012345678901234567890"
fi

### Test 4 ###
if [[ $t1 == 1 ]]
then
	echo "[Test 1.4] Emojis"
	$PATH_TO_CLIENT $pid "
Test 1.4:
⛴️ + 🌊 + 💥 = ❓
👦 + 👽 + 🚲 = ❓
🏰 + ❄️ + 👭 = ❓
" 
fi

### Test 5 ###
if [[ $t2 == 1 ]]
then
	echo "[Test 2.1] Speed test: Time to print 1 000 dot"
	time $PATH_TO_CLIENT $pid "
Test 2.1:
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
"
fi

### Test 6 ###
if [[ $t2 == 1 ]]
then
	echo "[Test 2.2] Speed test: Time to print 3 000 char"
	time $PATH_TO_CLIENT $pid "
Test 2.2:
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam mattis ullamcorper venenatis.
Curabitur auctor lectus sed ligula vehicula, eget blandit mauris commodo. Aliquam tempor pellentesque
faucibus. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.
Vestibulum hendrerit viverra ante sed ultrices. Aenean faucibus, erat at viverra efficitur,
enim lorem pretium orci, ut sollicitudin ex lacus posuere nibh. Suspendisse id lacus eu turpis pretium
ultricies eget at sem. Proin vulputate laoreet felis, sed dapibus ligula cursus id. In hac habitasse
platea dictumst. Fusce fermentum ipsum mauris, id volutpat erat auctor nec.

Praesent tellus sem, luctus in lacinia eu, rhoncus vitae mi. Phasellus nec leo rhoncus lorem efficitur
ultrices. Interdum et malesuada fames ac ante ipsum primis in faucibus. Sed pulvinar ultricies nulla vel
hendrerit. Ut tellus dolor, lacinia eu lectus varius, cursus commodo risus. Sed dictum quis velit nec
gravida. Morbi ultrices felis vel mauris fringilla, quis consectetur ligula elementum. Fusce vitae erat
neque. Aliquam varius odio nunc, id accumsan orci congue et. Etiam vehicula, diam vitae ultricies
suscipit, nibh massa consequat nisl, in cursus mi metus non massa. Proin libero diam, ullamcorper sed
lorem ut, rutrum interdum odio. In id elementum neque.

Etiam finibus arcu augue, quis fermentum nunc feugiat ac. Donec laoreet quam in felis imperdiet tincidunt
vitae non libero. Morbi gravida semper lacus, quis blandit augue. Vestibulum ante ipsum primis in faucibus
orci luctus et ultrices posuere cubilia curae; Proin tristique quam nec felis commodo auctor. Proin sit
amet consequat eros. Duis pulvinar at nibh eu dignissim. In hac habitasse platea dictumst. Donec erat
velit, vehicula quis elit non, cursus lacinia massa. Nullam velit lorem, pretium eu dictum eu, aliquam
in sem. Nunc eleifend ac risus ac mattis. Morbi commodo tellus dolor, eu fringilla massa finibus nec.
Sed rutrum lobortis auctor. Pellentesque maximus justo ut elit sodales ullamcorper. Vivamus viverra vel
elit vitae sagittis.

Maecenas iaculis consequat metus vehicula hendrerit. Donec turpis diam, placerat nec efficitur sit amet,
tincidunt at orci. Etiam purus felis, tempor in enim eu, condimentum faucibus nisi. Class aptent taciti
sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Etiam molestie, tellus a placerat
feugiat, tellus arcu iaculis nisl, in ornare metus nibh ut nisl. Aliquam nunc quam, feugiat et rutrum id,
luctus vitae orci. Fusce pharetra cursus malesuada. Interdum et malesuada fames ac ante ipsum primis in
faucibus.

Mauris molestie egestas neque nec fringilla. Vestibulum sed sapien sed orci aliquet efficitur. Nulla
massa justo, mattis ac mauris eget, pharetra interdum elit. Morbi mauris lacus, elementum eget nibh sed,
facilisis feugiat nisi. Integer elementum non dui ut pulvinar. Nam maximus malesuada lorem at tristique.
Cras pretium mattis erat vel cursus. Donec a ligula eget mauris auctor auctor quis eget arcu. In at
ornare odio. Mauris laoreet urna vestibulum porta tempus. Proin pharetra purus ex, in fermentum dui
aliquet ut. Aenean sed arcu nec lorem feugiat consequat. Nam congue ultrices porttitor. Vivamus pulvinar
ante ac magna fringilla sodales. Praesent molestie justo dui, eu hendrerit nisi eleifend sed.
"
fi

### Test 7 ###
if [[ $t3 == 1 ]]
then
	echo "[Test 3] Crash test: Sending big str with 20 000 char"
	$PATH_TO_CLIENT $pid "
Test 3:
                                               LL             A
                                               LL            A A
                                               LL           AA AA
                                               LL          AA   AA
                                               LL          AAAAAAA
                                               LL         AA     AA
                                               LL         AA     AA
                                               LLLLLLLLL  AA     AA
                                               LLLLLLLLL  AA     AA
TTTTTTTTTT   OOOOOOO   UU     UU  RRRRRRR              EEEEEEEEE  IIIIIIIIII  FFFFFFFFF  FFFFFFFFF  EEEEEEEEE  LL
TTTTTTTT  OOOOOOOOO  UU     UU  RRRRRRRR             EEEEEEEEE  IIIIIIIIII  FFFFFFFFF  FFFFFFFFF  EEEEEEEEE  LL
  TT      OO     OO  UU     UU  RR     RR            EE             II      FF         FF         EE         LL
  TT      OO     OO  UU     UU  RR     RR            EE             II      FF         FF         EE         LL
  TT      OO     OO  UU     UU  RRRRRRRR             EEEEEEEE       II      FFFFFFFF   FFFFFFFF   EEEEEEEE   LL
  TT      OO     OO  UU     UU  RR  RR               EE             II      FF         FF         EE         LL
  TT      OO     OO  UU     UU  RR   RR              EE             II      FF         FF         EE         LL
  TT      OOOOOOOOO  UUUUUUUUU  RR    RR             EEEEEEEEE  IIIIIIIIII  FF         FF         EEEEEEEEE  LLLLLLLLL
  TT       OOOOOOO    UUUUUUU   RR     RR            EEEEEEEEE  IIIIIIIIII  FF         FF         EEEEEEEEE  LLLLLLLLL
                                                         .
                                                         1
                                                         1
                                                         1
                                                         M
                                                         M
                                                         M
                                                         M
                                                        \\M/
                                                     . ' M \` .
                                                   \\##-#####-##/
                                                    \\# ##### #/
                                                  ###############
                                                  ###############
                                                   \\ ! ! ! ! ! /
                                                    )! ! ! ! !(
                                                    +---------+
                                                    +! ! ! ! !+
                                                    +----*----+
                                                   +\`. .':\`. .'+
                                                   + .^. : .^. +
                                                   +:...:*:...:+
                                                   +\`. .':\`. .'+
                                                   + .^. : .^. +
                                                   +:...:*:...:+
                                                   +\`. .':\`. .'+
                                                   +. ^. : .^ .+
                                                  +:....:*:....:+
                                                  +\` .  ':\`  . '+
                                                  +  .^. : .^.  +
                                                  +:....:*:....:+
                                                  +\` .. ':\` .. '+
                                                  +. '\` .:. '\` .+
                                                  +:....:*:....:+
                                                  + \`. .':\`. .' +
                                                  +   X  :  X   +
                                                  +.'  \`.:.'  \`.+
                                                 +:......*......:+
                                                 +\`.   .':\`.   .'+
                                                 +   X   :   X   +
                                                 + .' \`. : .' \`. +
                                                 +.......*.......+
                                                 +\` . . ':\` . . '+
                                                 +   X   :   X   +
                                                 + '   \` : '   \` +
                                                 +../########....+
                                                 +\`/#########\\ .'+
                                                +  ############   +
                                                + '############\`  +
                                                +:.......*.......:+
                                                + \` .  ' : \`  . ' +
                                                +    X   :   X    +
                                                + .'   \`.:.'   \`. +
                                                +:.......*.......:+
                                                +\`      ':\`      '+
                                               +  \`   '  :  \`   '  +
                                               +    X   : :   X    +
                                               +  '   \` : : '   \`  +
                                               +:.......*.*.......:+
                                               +\`      ': :\`      '+
                                               + \`   '  : :  \`   ' +
                                               +   X   : X :   X   +
                                              +  '   \` :' \`: '   \`  +
                                              +:.......*...*.......:+
                                              +\`      ':\` ':\`      '+
                                              + \`   '  : X :  \`   ' +
                                              +   X   :     :   X   +
                                              + '   \` :/   \\: '   \` +
                                             +:.......*.....*.......:+
                                             +\`      ':\`   ':\`      '+
                                             + \`   '  : \`.' :  \`   ' +
                                            +    X   :  ' \`  :   X    +
                                            +  '   \` :'     \`: '   \`  +
                                            +:.......*.......*.......:+
                                           + \`      ':\`     ':\`      ' +
                                           +  \` . '  :  \`.'  :  \` . '  +
                                          +    ' \`  :   ' \`   :  ' \`    +
                                          +. '    \` : '     \` : '    \` .+
                                         +..........*.........*..........+
                                         +  ###########################  +
                                         +  ###########################  +
                                        +   ###########################   +
                                     #########################################
                                    ###########################################
                                     \\   1   1   1   1   1   1   1   1   1   /
                                      )  1   1   1   1   1   1   1   1   1  (
                                      +-----:-----+-------------+-----:-----+
                                      +     :     +             +     :     +
                                     *------*-----*-------------*-----*------*
                                     +XXXXXXXXXXX+XXXXXXXXXXXXXXX+XXXXXXXXXXX+
                                     *-----*-----*---------------*-----*-----*
                                    + \`.   :  . '+               +\` .  :   .' +
                                    +    . : '   +               +   \` : .    +
                                   +    . *.    +                 +    .* .    +
                                   + . '  : \`.  +                 +  .' :  \` . +
                                  *:......*....:*                 *:....*......:*
                                  + \`.   :   . '+                 +\` .   :   .' +
                                 +     \`.:. '  +                   +  \` .:.'     +
                                 +   . '* \`.   +                   +   .' *\` .   +
                                + . '   :    \`.+                   +.'    :   \` . +
                                *:.....*.......*                   *.......*.....:*
                               +  \` .. :  .. ' +                   + \` ..  : .. '  +
                               +     . *'     +                     +     \`* .     +
                              +  .. ' :   \` . +                     + . '   : \` ..  +
                              *.:....*.......:*                     *:.......*....:.*
                             +   \` ..: . - '  +                     +  \` - . :.. '   +
                             +    .. * ..    +                       +    .. * ..    +
                        -------------------------------------------------------------------
                          1 +:       :      +:       :       :       :+      :       :+ 1
                          1+ :       :      +:       :       :       :+      :       : +1
                        ###################################################################
                         1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
                         1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
                         +---------------------------------------------------------------+
                        +! . ! . ! . ! . !+. ! . ! . ! . ! . ! . ! . ! .+! . ! . ! . ! . !+
                       +:!: :!: :!: :!: :!+ :!: :!: :!: :!: :!: :!: :!: +!: :!: :!: :!: :!:+
                       +.!.:.!.:.!.:.!.:.!+:.!.:.!.:.!.:.!.:.!.:.!.:.!.:+!.:.!.:.!.:.!.:.!.+
                      +XXXXXXXXXXXXXXXXXX+\\     \\  ..-#######-..  /     /+XXXXXXXXXXXXXXXXXX+
                     *-------------------* \\    .-' \\  1 1 1  / \`-.    / *-------------------*
                     +  \` .    : ..  '  +   \\.-' \\   .-------.   / \`-./   +  \`  .. :    . '  +
                    +.......:.*:........+ .-' \\  .-''         \`\`-.  / \`-. +........:*.:.......+
                   +    .  '  : \` .    +\\:  \\  -'                 \`-  /  :/+    . ' :  \`  .    +
                   +..:.......:.....:..+/ \\ .-'                     \`-. / \\+..:.....:.......:..+
                  +    \` .   :    .  ' + \\.'                           \`./ + \`  .    :   . '    +
                 +.........:.*..:.....+  /                               \\  +.....:..*.:.........+
                +     .  '  :   \` .   + /                                 \\ +   . '   :  \`  .     +
                +...:......:........:+ /                                   \\ +:........:..........+
               +    \`  .  :  .  '    +/                                     \\+    \`  .  :  .  '    +
              +...........*.........+                                         +.........*...........+
             +     .  '  :   \`  .   +                                         +   .  '   :  \`  .     +
            +...:.......:.........:+                                           +:.........:.......:...+
           +    \`  .    :   .   '  +                                           +  \`   .   :    .  '    +
          +..........:.*.:........+                                             +........:.*.:..........+
         +     .   '  :   \`  .    +                                             +    .  '   :  \`   .     +
        +...:.........:.........:+                                               +:.........:.........:...+
       +   \`   .     :     .   ' +                                               + \`   .     :     .   '   +
      +...........:.*..:........+                                                 +........:..*.:...........+
     +      .   '  :   \`  .     +                                                 +     .  '   :  \`   .      +
    +...:.........:..........:.+                                                   +.:..........:.........:...+
   +     \`  .     :      .  ' +                                                     + \`  .      :     .  '     +
  +            \` *  - '      +                                                       +      \` -  * '            +
 -----------------------------------------------------------------------------------------------------------------                        
"
fi

$PATH_TO_CLIENT $pid "ALL TEST FINISHED"

echo ""
echo "If all was corrrectly display on your server terminal: Perfect, well done! 💪"
