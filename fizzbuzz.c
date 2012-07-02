/*
 *  fizzbuzz.c
 *
 *  A collection of solutions to the so-called "fizz buzz" test, as proposed by I. Ghory
 * 
 *  from the very reasonable to the very insane, implemented in plain C89.
 *  (TODO: not insane enough. need more versions)
 *
 *  by Thomas Gruetzmacher (tomaes@32x.de)
 *
 *  Licence: This source code is in the public domain.
 *
 */


#include <stdio.h>
#include <stdlib.h>


#define V3




int main(int argc, char ** argv)
{

 int i, range = 1000;



/* a no-nonsense, standard solution, most programmers would think of first. */
#ifdef V1
 for( i = 0; i <= range; i++ )
 {      
       if (i%5 == 0 && i%3 == 0) 
          puts("fizzbuzz"); 
       else
       if (i%3 == 0) 
          puts("fizz"); 
       else
       if (i%5 == 0) puts("buzz"); 
 }
#endif


  
/* somewhat optimized, still a very reasonable and readable version */
#ifdef V2
 for( i = 0; i++ < range; )
 {      
       if (i%15 == 0) 
          puts("fizzbuzz"); 
       else
       if (i%3 == 0) 
          puts("fizz"); 
       else
       if (i%5 == 0) puts("buzz"); 
 }
#endif


  
/* some further tweaking. not as obvious as before, but still reasonable */  
#ifdef V3
 for( i = 0; i++ < range; )
 {      
       if (!(i%15)) 
          puts("fizzbuzz"); 
       else
       if (!(i%3)) 
          puts("fizz"); 
       else
       if (!(i%5)) puts("buzz"); 
 }  
#endif



/* here's a first solution that is a little more obscure and not very readable any more */ 
#ifdef V4 
 char *fb[] = { "fizz", "buzz", "fizzbuzz" };  

 for( i = 0; i++ < range; )
     !(i%15) ? puts(fb[2]) : !(i%5) ? puts(fb[1]) : !(i%3) ? puts(fb[0]) : 0; 
#endif



/* let's put everything in one printf(), quite raunchy version. */
#ifdef V5
 for(i = 0; i++ < range;) printf("\n%s%s%s", !(i%3)?"fizz ":"", !(i%5)?"buzz ":"", !(i%15)?"fizzbuzz":"" );
#endif
 
 
 
/* And another fairly liberal interpretation of the test that is not using modulo any more. */ 
#ifdef V6
 for( i = 0; i++ < range; )
 {
    printf("\ni:%d, fizz?: %s",     i, ( (i/3.  - (float)(i/3))  ) ? ":(" :":)");
    printf("\ni:%d, buzz?: %s",     i, ( (i/5.  - (float)(i/5))  ) ? ":(" :":)");
    printf("\ni:%d, fizzbuzz?: %s", i, ( (i/15. - (float)(i/15)) ) ? ":(" :":)");   
 }
#endif


  
/* Now let's up the ante a bit and show a glimpse of what's possible, but certainly
   not desirable. :) You could still figure it out, but you'd need some time, I guess.
   All the terrible things happen in the array init parts, the main loop is still 
   unobfuscated yet. */  
#ifdef OBF1
 int k = 0142; 
 i = (~~!'\0'<<0xA)-(!'\0'<<5)+(!'\0'<<3);
        
 char s[] = {k, k+4, k+7, k+19, k+24, !!(k-~~k)}, f[*s-0x5d], b[(!i|!i-~!-03)*5]; 
    
 f[!s] = s[!!k]; 
 f[1?1&!!i+!i:!i] = s[1<<1]; 
 f[(!!k^!k)<<!!k] = *(s+(0x400>>010)); 
 f[3] = s[(-1^!-1)&(!!~1<<2)]; 
 f[1^!-1+01^~-1+1<<2-!'?'] = *(s+!!~0+2*2);
    
 b[!s] = s[!f]; 
 b[0?0:!!'Z'] = s[-1&0x3]; 
 b[~0*-1<<1] = *(f+!0*2); 
 b[3] = f[1^!-1+2]; 
 b[~!+04?04:04] = s[~0&0x10-~~0xb];
   
 while(i--) (!(i%15))?printf("%s%s\n",f,b):(!(i%5))?puts(b):(!(i%3))?puts(f):"";
#endif  
    

    
#ifdef OBF2    
/* TODO: the borderline insane version goes here. :) */
#endif

  
  system("PAUSE");	
  return 0;
}
