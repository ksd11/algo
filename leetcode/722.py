class Solution:

    def multi_consume(self, s: str):
        for idx in range(len(s)):
            if idx == len(s) - 1:
                return False, None
            if s[idx] == '*' and s[idx + 1] == '/':
                return True, idx + 2
        return False, None

    def removeComments(self, source: list[str]) -> list[str]:
        dest = []
        i = 0
        prefix_line = ''
        while i < len(source):
            line = prefix_line if len(prefix_line)!=0 else source[i]
            prefix_line = ''
            length = len(line)
            ok = True
            for j in range(length - 1):
                if line[j] == '/' :
                    if line[j+1] == '/':
                        ok = False
                        if j!=0 or len(prefix_line) != 0:
                            dest.append(prefix_line + line[:j])
                        break # 单行注释
                    elif line[j+1] == '*':
                        ok = False
                        prefix_line = line[:j]
                        line = line[j+2:]
                        end, idx = self.multi_consume(line)
                        while not end:
                            i+=1
                            line = source[i]
                            end, idx = self.multi_consume(line)
                        
                        if idx != len(line) or len(prefix_line) != 0:
                            prefix_line = prefix_line + line[idx:]
                            i = i-1
                        #     dest.append(prefix_line+line[idx:])
                        break
            if ok:
                dest.append(line)
            i += 1

        return dest


if __name__ == '__main__':
    solution = Solution()
    # question_input = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
    # question_input = ["void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}"]
    question_input = ["main() { ", "  int a = 1; /* Its comments here ", "", "  ", "  */ return 0;", "} "]
    question_ouput = solution.removeComments(source=question_input)
    print(question_ouput)
