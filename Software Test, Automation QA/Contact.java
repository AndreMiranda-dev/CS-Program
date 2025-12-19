// Defines a Contact class to store contact information
public class Contact {
    // Unique, immutable contact ID (max 10 characters)
    private final String contactId;
    // Updatable fields with validation constraints
    private String firstName;
    private String lastName;
    private String phone;
    private String address;

    // Constructor enforces all validation rules for contact creation
    public Contact(String contactId, String firstName, String lastName, String phone, String address) {
        // Validate contact ID: not null, max 10 characters
        if (contactId == null || contactId.length() > 10)
            throw new IllegalArgumentException("Invalid contact ID");
        // Validate first name: not null, max 10 characters
        if (firstName == null || firstName.length() > 10)
            throw new IllegalArgumentException("Invalid first name");
        // Validate last name: not null, max 10 characters
        if (lastName == null || lastName.length() > 10)
            throw new IllegalArgumentException("Invalid last name");
        // Validate phone: not null, exactly 10 digits
        if (phone == null || !phone.matches("\\d{10}"))
            throw new IllegalArgumentException("Invalid phone number");
        // Validate address: not null, max 30 characters
        if (address == null || address.length() > 30)
            throw new IllegalArgumentException("Invalid address");

        // Assign validated values to fields
        this.contactId = contactId;
        this.firstName = firstName;
        this.lastName = lastName;
        this.phone = phone;
        this.address = address;
    }

    // Getter for contact ID (not updatable)
    public String getContactId() { return contactId; }

    // Getter for first name
    public String getFirstName() { return firstName; }

    // Getter for last name
    public String getLastName() { return lastName; }

    // Getter for phone number
    public String getPhone() { return phone; }

    // Getter for address
    public String getAddress() { return address; }

    // Setter for first name with validation
    public void setFirstName(String firstName) {
        if (firstName == null || firstName.length() > 10)
            throw new IllegalArgumentException("Invalid first name");
        this.firstName = firstName;
    }

    // Setter for last name with validation
    public void setLastName(String lastName) {
        if (lastName == null || lastName.length() > 10)
            throw new IllegalArgumentException("Invalid last name");
        this.lastName = lastName;
    }

    // Setter for phone number with validation
    public void setPhone(String phone) {
        if (phone == null || !phone.matches("\\d{10}"))
            throw new IllegalArgumentException("Invalid phone number");
        this.phone = phone;
    }

    // Setter for address with validation
    public void setAddress(String address) {
        if (address == null || address.length() > 30)
            throw new IllegalArgumentException("Invalid address");
        this.address = address;
    }
}