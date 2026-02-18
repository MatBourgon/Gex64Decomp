if [ $# -eq 0 ];
then
    grep -c ^ asm/nonmatchings/*/func_*.s | awk '{print $2"\t"$1}' FS=":" | sort -n | head -1 | awk '{print $2}' FS="\t"
else
    grep -c ^ asm/nonmatchings/$1/func_*.s | awk '{print $2"\t"$1}' FS=":" | sort -n | head -1 | awk '{print $2}' FS="\t"
fi