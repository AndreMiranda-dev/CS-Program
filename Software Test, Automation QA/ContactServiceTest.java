import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

// Unit tests for the ContactService class
public class ContactServiceTest {
    private ContactService service;
    private Contact contact;

    // Set up a fresh ContactService and add a default contact before each test
    @BeforeEach
    public void setup() {
        service = new ContactService();
        contact = new Contact("001", "Alice", "Smith", "1234567890", "456 Elm St");
        service.addContact(contact);
    }

    @Test
    public void testAddValidContact() {
        // Test adding a new contact with a unique ID
        Contact newContact = new Contact("002", "Bob", "Jones", "0987654321", "789 Oak St");
        service.addContact(newContact);
        assertEquals("Bob", newContact.getFirstName());
    }

    @Test
    public void testAddDuplicateContactId() {
        // Test that adding a contact with an existing ID throws an exception
        assertThrows(IllegalArgumentException.class, () -> {
            service.addContact(new Contact("001", "Bob", "Jones", "0987654321", "789 Oak St"));
        });
    }

    @Test
    public void testDeleteContact() {
        // Test deleting an existing contact and confirm it's removed
        service.deleteContact("001");
        assertThrows(IllegalArgumentException.class, () -> service.deleteContact("001"));
    }

    @Test
    public void testDeleteNonexistentContact() {
        // Test that deleting a contact that doesn't exist throws an exception
        assertThrows(IllegalArgumentException.class, () -> service.deleteContact("999"));
    }

    @Test
    public void testUpdateFirstName() {
        // Test updating the first name of an existing contact
        service.updateFirstName("001", "Eve");
        assertEquals("Eve", contact.getFirstName());
    }

    @Test
    public void testUpdateLastName() {
        // Test updating the last name of an existing contact
        service.updateLastName("001", "Johnson");
        assertEquals("Johnson", contact.getLastName());
    }

    @Test
    public void testUpdatePhone() {
        // Test updating the phone number of an existing contact
        service.updatePhone("001", "0987654321");
        assertEquals("0987654321", contact.getPhone());
    }

    @Test
    public void testUpdateAddress() {
        // Test updating the address of an existing contact
        service.updateAddress("001", "321 Pine St");
        assertEquals("321 Pine St", contact.getAddress());
    }

    @Test
    public void testUpdateNonexistentContact() {
        // Test that updating a contact that doesn't exist throws an exception
        assertThrows(IllegalArgumentException.class, () -> service.updateFirstName("999", "NewName"));
    }
}