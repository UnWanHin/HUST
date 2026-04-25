import re

def is_wuhan_id_card(id_card):
    # 正则表达式：以42开头，后面跟随16位数字和1个校验位（数字或字母X）
    pattern = r'^4201\d{14}'

    if re.match(pattern, id_card):
        return True
    else:
        return False

def main():

    id_card = input("请输入身份证号: ")
    if is_wuhan_id_card(id_card):
        print("该身份证号是武汉市的身份证号。")
    else:
        print("该身份证号不是武汉市的身份证号。")

if __name__ == "__main__":
    main()
