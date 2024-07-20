import os

class Contact:
    def __init__(self, name, phone, email, address):
        self.name = name
        self.phone = phone
        self.email = email
        self.address = address

    def __str__(self):
        return f"Name: {self.name}, Phone: {self.phone}, Email: {self.email}, Address: {self.address}"

class ContactManager:
    def __init__(self, filename="contacts.txt"):
        self.filename = filename
        self.contacts = []
        self.load_contacts()

    def load_contacts(self):
        if os.path.exists(self.filename):
            with open(self.filename, "r") as file:
                for line in file:
                    name, phone, email, address = line.strip().split(',')
                    self.contacts.append(Contact(name, phone, email, address))

    def save_contacts(self):
        with open(self.filename, "w") as file:
            for contact in self.contacts:
                file.write(f"{contact.name},{contact.phone},{contact.email},{contact.address}\n")

    def add_contact(self, contact):
        self.contacts.append(contact)
        self.save_contacts()

    def view_contacts(self):
        for contact in self.contacts:
            print(contact)

    def search_contact(self, search_term):
        results = [contact for contact in self.contacts if search_term.lower() in contact.name.lower() or search_term in contact.phone]
        return results

    def update_contact(self, search_term, new_contact):
        for i, contact in enumerate(self.contacts):
            if search_term.lower() in contact.name.lower() or search_term in contact.phone:
                self.contacts[i] = new_contact
                self.save_contacts()
                return True
        return False

    def delete_contact(self, search_term):
        for i, contact in enumerate(self.contacts):
            if search_term.lower() in contact.name.lower() or search_term in contact.phone:
                del self.contacts[i]
                self.save_contacts()
                return True
        return False

def main():
    manager = ContactManager()

    while True:
        print("\nContact Manager")
        print("1. Add Contact")
        print("2. View Contacts")
        print("3. Search Contact")
        print("4. Update Contact")
        print("5. Delete Contact")
        print("6. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            name = input("Enter name: ")
            phone = input("Enter phone number: ")
            email = input("Enter email: ")
            address = input("Enter address: ")
            manager.add_contact(Contact(name, phone, email, address))
        elif choice == "2":
            manager.view_contacts()
        elif choice == "3":
            search_term = input("Enter name or phone number to search: ")
            results = manager.search_contact(search_term)
            for contact in results:
                print(contact)
        elif choice == "4":
            search_term = input("Enter name or phone number of the contact to update: ")
            name = input("Enter new name: ")
            phone = input("Enter new phone number: ")
            email = input("Enter new email: ")
            address = input("Enter new address: ")
            if manager.update_contact(search_term, Contact(name, phone, email, address)):
                print("Contact updated successfully.")
            else:
                print("Contact not found.")
        elif choice == "5":
            search_term = input("Enter name or phone number of the contact to delete: ")
            if( manager.delete_contact(search_term)):
                print("Contact deleted successfully.")
            else:
                print("Contact not found.")
        elif choice == "6":
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
