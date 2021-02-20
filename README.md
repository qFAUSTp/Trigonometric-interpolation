# Trigonometric interpolation
This project calculate trigonometric polynomial coefficients that can be used in trigonometric interpolation.

https://en.wikipedia.org/wiki/Trigonometric_interpolation

In this project used next trigonometric polynomial: 

![alt text](https://cdn.discordapp.com/attachments/812333574467354635/812684433294491658/Trigonometric_polynomial.jpg)

# How to use:
The program is taked data from input_data.txt file (each .text line must contain two real (double, to be more precise) number separated by a space {x y} ).

Data that you put must satisfy the following condition:

![alt text](https://cdn.discordapp.com/attachments/812333574467354635/812747992598839326/CodeCogsEqn_1.png)

And the amount of data must be an even number.

As result, program will calculate all needed coefficient, that can be used in upper polynomial.

Here is some example:

> C:\Projects\Trigonometric-interpolation>Interpolation.exe 
> 
> Loading data from .txt \n
> 
> All data is loaded... 
>
>  ---------------
> 
> a_0: 16.3333
>
> a_k: -2.5 3.83333
> 
> b_k: 0.288675 1.44338
> 
> a_m: -9

Using this coefficients with polynomial got something looks this way:

![alt text](https://cdn.discordapp.com/attachments/812333574467354635/812754131516915722/untitled.png)

Blue points here it's data from input_data.txt scaled to *2pi*.

The red curve it's calculated trigonometric polynomial.
