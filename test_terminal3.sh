show_sequence() { 
    read -rsn1 key 
    echo -n "Вы ввели: " 
    printf "%s\n" "$key" | xxd 
} 
 
while true; do 
    show_sequence 
done