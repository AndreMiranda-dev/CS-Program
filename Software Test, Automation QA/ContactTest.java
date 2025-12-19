import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Arrays;

// Unit tests for the Contact class
public class ContactTest {

    @Test
    public void testValidContactCreation() {
        // Test that a valid contact is created with correct field values
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Main St");
        assertEquals("1234567890", contact.getContactId());
        assertEquals("John", contact.getFirstName());
        assertEquals("Doe", contact.getLastName());
        assertEquals("1234567890", contact.getPhone());
        assertEquals("123 Main St", contact.getAddress());
    }

    @Test
    public void testContactIdImmutability() {
        // Ensure that there is no setter method for contactId (i.e., it's immutable)
        boolean hasSetter = Arrays.stream(Contact.class.getDeclaredMethods())
            .anyMatch(m -> m.getName().equals("setContactId"));
        assertFalse(hasSetter, "Contact ID should be immutable and have no setter");
    }

    @Test
    public void testNullFields() {
        // Test that null values for any field throw an IllegalArgumentException
        assertThrows(IllegalArgumentException.class, () -> new Contact(null, "John", "Doe", "1234567890", "123 Main St"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("123", null, "Doe", "1234567890", "123 Main St"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("123", "John", null, "1234567890", "123 Main St"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("123", "John", "Doe", null, "123 Main St"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("123", "John", "Doe", "1234567890", null));
    }

    @Test
    public void testBoundaryConditions() {
        // Test that fields at their maximum allowed lengths are accepted
        String tenChars = "ABCDEFGHIJ"; // 10 characters
        String thirtyChars = "123456789012345678901234567890"; // 30 characters
        Contact contact = new Contact(tenChars, tenChars, tenChars, "0123456789", thirtyChars);
        assertEquals(tenChars, contact.getContactId());
        assertEquals(tenChars, contact.getFirstName());
        assertEquals(tenChars, contact.getLastName());
        assertEquals("0123456789", contact.getPhone());
        assertEquals(thirtyChars, contact.getAddress());
    }

    @Test
    public void testUpdateFirstName() {
        // Test updating the first name
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        contact.setFirstName("Jane");
        assertEquals("Jane", contact.getFirstName());
    }

    @Test
    public void testUpdateLastName() {
        // Test updating the last name
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        contact.setLastName("Smith");
        assertEquals("Smith", contact.getLastName());
    }

    @Test
    public void testUpdatePhone() {
        // Test updating the phone number
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        contact.setPhone("0987654321");
        assertEquals("0987654321", contact.getPhone());
    }

    @Test
    public void testUpdateAddress() {
        // Test updating the address
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        contact.setAddress("789 Elm St");
        assertEquals("789 Elm St", contact.getAddress());
    }
}