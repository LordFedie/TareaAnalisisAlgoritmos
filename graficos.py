import pandas a s pd
import m a t p l o t l i b
import m a t p l o t l i b . p y p l o t a s p l t
# open a c s v f i l e
d f = pd . r e a d c s v ( ’ data . c s v ’ )
# g r a p h i c each l i n e
# p l o t ( x=v a l u e s , y=v a l u e s , l a b e l , p o i n t s marker )
p l t . p l o t ( d f [ ’ n ’ ] , d f [ ’ b r u t e f o r c e ’ ] , l a b e l = ’ Brute Force ’ ,
marker = ’ o ’ )
p l t . p l o t ( d f [ ’ n ’ ] , d f [ ’ d i v i d e c o n q u e r ’ ] , l a b e l = ’ D i v i d e and Conquer ’ ,
marker = ’ s ’ )
# x=l a b e l s and y=l a b e l s
p l t . x l a b e l ( ’ Running time ( n a n o s e c o n d s ) ’ )
p l t . y l a b e l ( ’ Input time ( l o g ) ’ )
# l o g =s c a l e
p l t . y s c a l e ( ’ l o g ’ )
# show l e g e n d
p l t . l e g e n d ( )
#s a v e g r a p h i c i n a f i l e
p l t . s a v e f i g ( ’ p l o t . png ’ )
Tarea 1: Min Distance 3/3
