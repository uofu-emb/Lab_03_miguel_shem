# CMake generated Testfile for 
# Source directory: /home/shem/lab03/rtos.template/test
# Build directory: /home/shem/lab03/rtos.template/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(simulate_mytest "RENODE-NOTFOUND" "--disable-xwt" "--port" "-2" "--pid-file" "renode.pid" "--console" "-e" "\$ELF=@/home/shem/lab03/rtos.template/build/test/mytest.elf; \$WORKING=@/home/shem/lab03/rtos.template; include @/home/shem/lab03/rtos.template/test/simulate.resc; start")
set_tests_properties(simulate_mytest PROPERTIES  _BACKTRACE_TRIPLES "/home/shem/lab03/rtos.template/test/CMakeLists.txt;39;add_test;/home/shem/lab03/rtos.template/test/CMakeLists.txt;0;")
