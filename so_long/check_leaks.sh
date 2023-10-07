while true; do
    leaks --list so_long  # 메모리 누수 검사
    sleep 1            # 1초 동안 대기
done