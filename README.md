---

# Bank Management System

This Bank Management System is a C++ console application with a comprehensive feature set for managing clients, accounts, and transactions. Below is an overview of the system's core functionality and features.

## Features

- Show, add, delete, update and find clients, and perform many transactions for each one or between!
- Manage all users on the system and add, delete, update or find users. 
- All users have permissions that allow or restrict them to/from control and manipulate the system.
- Save and show all login registers in the system.
- Follow all currencies at the system and perform many operations like convert between currencies.

---

### **Login System**
   - The console opens with a login screen displaying the date and prompts for a username and password.
   - Users have three attempts to enter correct credentials before the system locks them out, displaying a message about the lock status.

### **Main Menu**
   - After successful login, users can access a Main Menu offering various options:
     - **Show Client List**
     - **Add New Client**
     - **Delete Client**
     - **Update Client Info**
     - **Find Client**
     - **Transactions**
     - **Manage Users**
     - **Login Register**
     - **Currency Exchange**
     - **Logout**

### 1. **Show Client List**
   - Displays all registered clients in a formatted table, including their account number, name, contact information, PIN, and balance.

### 2. **Add New Client**
   - A screen allows users to add a new client by providing essential details, such as account number, name, email, phone, PIN code, and balance.

### 3. **Delete Client**
   - Enables users to remove a client's account from the system using the client's account number.

### 4. **Update Client**
   - Allows updating a client's details, excluding the account number.

### 5. **Find Client**
   - A search feature to find a client based on their account number, displaying relevant information if found.

### 6. **Transactions Menu**
   - **Deposit / Withdraw**: Manages deposits and withdrawals for clients' accounts, checking for sufficient balance.
   - **Total Balances**: Lists each client’s balance and displays the total balance across all accounts.
   - **Transfer**: Facilitates transfers between accounts, verifying that the sender has sufficient funds.
   - **Transfer Logs**: Displays a history of all transfers, including date/time, involved accounts, amounts, and user details.

### 7. **Manage Users**
- A powerful section to manage all users in the system and show all them details.
   - **Show List Users**: Lists all users with login permissions and their access levels.
   - **Add User**: Adds a new user, specifying access permissions.
   - **Delete User**: Removes a user based on their username.
   - **Update User**: Updates user information and access permissions.
   - **Find User**: Searches for a user by username, displaying relevant details if found.

### 8. **Login Register**
   - Displays a log of all system logins, including date and time, username, password, and permission level for each login attempt.
   - The list appears in a table format with headers:
     - **Date/Time** - The exact login time.
     - **User Name** - The name of the user logging in.
     - **Password** - Password entered during login.
     - **Permissions** - Permission level of the user.
   - Allows administrators to review login history for security and user management.

### 9. **Currency Exchange**
   - A comprehensive currency exchange menu allowing for the management of multiple currency-related operations. Menu options:
     - **Currency List**: Displays a list of all supported currencies, each with its country, currency code, currency name, and exchange rate.
     - **Find Currency**: Allows searching for a specific currency by country name or currency code.
     - **Update Rate**: Updates the exchange rate for a specific currency by entering its currency code.
     - **Currencies Calculator**: Converts a specified amount from one currency to another, showing details for both currencies and the converted amount.

## 10. **Logout**
   - Logs the user out of the system and returns them to the login screen.
