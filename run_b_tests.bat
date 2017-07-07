call rake test:test_b_traffic_light_fsm.c 
echo "Run Tests"
gcc.exe "build/test/out/test_b_traffic_light_fsm_runner.o" "build/test/out/test_b_traffic_light_fsm.o" "build/test/out/unity.o" "build/test/out/cmock.o" -o "build/test/out/test_b_traffic_light_fsm.exe"
.\build\test\out\test_b_traffic_light_fsm.exe
