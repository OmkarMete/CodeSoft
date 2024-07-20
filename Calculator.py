def main():
    
    num1 = int(input("Enter the first number : "))
    num2 = int(input("Enter the second number : "))
    
    print("Select operation:")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    
    choice = input("Enter your choice (1/2/3/4) : ")
    
    if choice == "1":
        result = num1 + num2
        print(f"The result is : {result}")
    elif choice == "2":
        result = num1 - num2
        print(f"The result is : {result}")
    elif choice == "3":
        result = num1 * num2
        print(f"The result is : {result}")
    elif choice == "4":
        if num2 != 0:
            result = num1 / num2
            print(f"The result is : {result}")
        else:
            print("Error!!! Division by zero is not possible.")
    else:
        print("Invalid choice")

if __name__ == "__main__":
    main()
