#### **Practical 1**

1.3

I have face a problem in...

if(sentence\[i]==' ')

&#x20;       {

&#x20;           if(length>longest)

&#x20;           {

&#x20;               longest=length;

&#x20;               endIndex=i-1;

&#x20;           }                                                                                           

&#x20;           length=0;

&#x20;       }

&#x20;       else

&#x20;       {

&#x20;           length++;

&#x20;       }

Now here in line...  endIndex=i-1; I can't understand why I took i-1 , not i+1.

Solution is --- 



&#x20;   **1 2 3 4 5** **6 7 8 9 10 11 12 ..**

&#x20;   **H e l l o \_ L e t \_\_  u  s  g o.**



Here we are stopped at i=5 , now (i-1 = 4) . So ' **Hello** ' is ended at position ' **4** '.  So we took ' **endIndex = i-1 '**





