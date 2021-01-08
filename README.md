# Recover
### A program that recovers JPEGs from a forensic image

# Background
In anticipation of this problem, we spent the past several days taking photos of people we know, all of which were saved on a digital camera as JPEGs on a memory card. (Okay, it’s possible we actually spent the past several days on Facebook instead.) Unfortunately, we somehow deleted them all! Thankfully, in the computer world, “deleted” tends not to mean “deleted” so much as “forgotten.” Even though the camera insists that the card is now blank, we’re pretty sure that’s not quite true. Indeed, we’re hoping (er, expecting!) you can write a program that recovers the photos for us!
Even though JPEGs are more complicated than BMPs, JPEGs have “signatures,” patterns of bytes that can distinguish them from other file formats. Specifically, the first three bytes of JPEGs are
```
0xff 0xd8 0xff
```
from first byte to third byte, left to right. The fourth byte, meanwhile, is either 
```0xe0```,```0xe1```,```0xe2```,```0xe3```,```0xe4```,```0xe5```,```0xe6```,```0xe7```,```0xe8```,```0xe9```,```0xea```,```0xeb```,```0xec```,```0xed```,```0xee```,```0xef```. Put another way, the fourth byte’s first four bits are ```1110```.
