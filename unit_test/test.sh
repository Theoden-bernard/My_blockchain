SRC=../src/
FUNC_LIST=`ls ${SRC}` 

OIFS=$IFS
IFS="
"

for fun in $FUNC_LIST; do
    unit=${SRC}/${fun}
    if [ -d $unit ]; then
        echo "-- TESTING $unit"
        (cd $unit; make; make test)
    fi
done 
IFS=$OIFS