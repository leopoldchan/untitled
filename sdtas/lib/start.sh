cd /data/data/com.sdt.sdtas/files/sdtas/lib
rm -f whsdk.log
export LD_LIBRARY_PATH=/data/data/com.sdt.sdtas/files/sdtas/lib
./sdtmqb &
sleep 1
./DCContainer &
./NAClient &