max=1000
if ln ex2.txt ex2.txt.lock
then
    for i in `seq 2 $max`
    do  
        y=$(tail -n 1 < ex2.txt)
        x=$(($y + 1))
        echo "$x" >> ex2.txt
    done
fi
rm ex2.txt.lock