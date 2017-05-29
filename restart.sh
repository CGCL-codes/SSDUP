pid=`ps aux | grep pvfs | grep sbin | awk '{print $2}'`                        
#echo $pid                                 
kill -s 9 $pid
/vpublic01/liming/clean.sh
sleep 1
/vpublic01/liming/test/orangefs_install/sbin/pvfs2-server /vpublic01/liming/orangefs-server.conf /vpublic01/liming/wb_info.conf -f
#/vpublic01/liming/orangefs_install_iswc/sbin/pvfs2-server /vpublic01/liming/orangefs-server.conf -f
sleep 2
/vpublic01/liming/test/orangefs_install/sbin/pvfs2-server /vpublic01/liming/orangefs-server.conf /vpublic01/liming/wb_info.conf
##/vpublic01/liming/orangefs_install_iswc/sbin/pvfs2-server /vpublic01/liming/orangefs-server.conf 
