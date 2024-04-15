#очищает экран;
#➢ выводит псевдографическую рамку, начиная с 5 символа 10 строки, размером
#8 строк на 8 столбцов;
#➢ с помощью псевдографического символа «закрашенный прямоугольник»
#(ACS_CKBOARD) в рамке выводится большой символ, соответствующий
#последней цифре дня вашего рождения (например, день рождения 13 января
#1991 года, выводится цифра 3)

echo -e "\E[H\E[J"
echo -e "\E[10;5H"
echo -e "\E(0"
#echo -e "++\054\054--..00``aaffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~"
echo -e "\E[10;5Hlqqqqqqqqk"
echo -ne "\E[11;5Hx"
echo -e "\E[11;14Hx"
echo -e "\E[11;6Haa"
echo -e "\E[11;12Haa"
echo -ne "\E[12;5Hx"
echo -e "\E[12;14Hx"
echo -e "\E[12;6Haa"
echo -e "\E[12;12Haa" 
echo -ne "\E[13;5Hx"
echo -ne "\E[13;6Haa"
echo -ne "\E[13;12Haa" 
echo -e "\E[13;14Hx"
echo -ne "\E[14;5Hx"
echo -ne "\E[14;6Haaaaaaaa"
echo -e "\E[14;14Hx"
echo -ne "\E[15;5Hx"
echo -ne "\E[15;12Haa"
echo -e "\E[15;14Hx"
echo -ne "\E[16;5Hx"
echo -ne "\E[16;12Haa"
echo -e "\E[16;14Hx"
echo -ne "\E[17;5Hx"
echo -ne "\E[17;12Haa"
echo -e "\E[17;14Hx"
echo -e "\E[18;5Hmqqqqqqqqj"
echo -e "\E(B"