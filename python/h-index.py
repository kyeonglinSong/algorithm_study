def solution(citations):
    n = len(citations)
    for i, h in enumerate(sorted(citations)):
        if h >= n-i:
            return n-i
    return 0

# 여전히 잘 모르겠다 다시 풀어보자