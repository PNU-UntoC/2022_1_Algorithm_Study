def or12(x):
    a=False
    for i in x:
        if x.count(i) == 1:
            a=True
        else:
            continue
    return a

  def main():
  word = sorted([i for i in input().lower()])
  word2 = sorted(list(set(word)))
  num=[word.count(i) for i in word2]
  print(word2[num.index(max(num))].upper() if or12(num) else "?")

if __name__ == "__main__":
  main()
