f = open('cake.obj', 'r', encoding='UTF8')
newf = open('새파일.obj', 'w')

while True:
    line = f.readline()
    if not line: break
    subline = line.split()
    if len(subline) > 0 and subline[0] == 'f':
        n_points = len(subline) - 1
        for i in range(n_points - 2):
            newline = 'f ' + subline[1] + ' ' + subline[i + 2] + ' ' + subline[i + 3] + '\n'
            newf.write(newline)
    else:
        newf.write(line)
    # 버튼 생성
    
f.close()
newf.close()