import java.util.HashMap;
import java.util.Map;

// Service class to manage Contact objects in memory
public class ContactService {
    // Stores contacts using contactId as the unique key
    private final Map<String, Contact> contacts = new HashMap<>();

    // Adds a new contact if the ID is unique
    public void addContact(Contact contact) {
        if (contacts.containsKey(contact.getContactId()))
            throw new IllegalArgumentException("Contact ID already exists");
        contacts.put(contact.getContactId(), contact);
    }

    // Deletes a contact by ID if it exists
    public void deleteContact(String contactId) {
        if (!contacts.containsKey(contactId))
            throw new IllegalArgumentException("Contact ID not found");
        contacts.remove(contactId);
    }

    // Updates the first name of a contact by ID
    public void updateFirstName(String contactId, String firstName) {
        getContact(contactId).setFirstName(firstName);
    }

    // Updates the last name of a contact by ID
    public void updateLastName(String contactId, String lastName) {
        getContact(contactId).setLastName(lastName);
    }

    // Updates the phone number of a contact by ID
    public void updatePhone(String contactId, String phone) {
        getContact(contactId).setPhone(phone);
    }

    // Updates the address of a contact by ID
    public void updateAddress(String contactId, String address) {
        getContact(contactId).setAddress(address);
    }

    // Helper method to retrieve a contact by ID or throw an error if not found
    private Contact getContact(String contactId) {
        Contact contact = contacts.get(contactId);
        if (contact == null)
            throw new IllegalArgumentException("Contact ID not found");
        return contact;
    }
}