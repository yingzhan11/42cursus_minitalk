# useful reference

1- sending and handling signal in C https://www.youtube.com/watch?v=83M5-NPDeWs

2- Unix signal https://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html

3- wiki for this project https://github.com/mlanca-c/Minitalk/wiki (very useful)

# some tips



1-when input a huge string more than 20 000, sometimes it stop, not crash or any error, just stop. This is not happen on my own computer, only in hive mac. also test someone else code, has the same problem, so it maybe the machine problem? not sure

2-check the return value of kill and sigaction < 0, printf error info and exit

**Done**

this appoarch is a blind way, no feedback loop, use usleep. it has some problem when test a hugh string, more than 1000 or 3000, it shows some ramdom charater in server which is different to client string.

the single way signal is not safe enough, as it is hard to control the delay time for each char.
