#Для проверки сформируйте последовательность escape-команд, выполняющую следующие действия:
#➢ очищает экран;
#➢ выводит в пятой строке, начиная с 10 символа Ваше имя красными буквами на черном фоне;
#➢ в шестой строке, начиная с 8 символа Вашу группу зеленым цветом на белом фоне;
#➢ перемещает курсор в 10 строку, 1 символ и возвращает настройки цвета в значения «по умолчанию».

echo -e "\033[H\033[J"
echo -e "\033[48:5;47m""\033[38\:5;31m" 
echo -e "\033[5;10H""\033[s""Gorodilov Pave;" 
echo -e "\033[48:5;m""\033[38:5;32m"
echo -e "\033[6;8H""\033[s""IV-222" 
echo -e "\033[10;1H""\033[s""\033[49;m""\033[39;m" 