**TODO** when input a huge string more than 20 000, sometimes it stop, not crash or any error, just stop. This is not happen on my own computer, only in hive mac. also test someone else code, has the same problem, so it maybe the machine problem? not sure

**Done**

this appoarch is a blind way, no feedback loop, use usleep. it has some problem when test a hugh string, more than 1000 or 3000, it shows some ramdom charater in server which is different to client string.

the single way signal is not safe enough, as it is hard to control the delay time for each char.
