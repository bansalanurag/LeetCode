import java.util.UUID;
public class Codec {

    private HashMap<String, String> m = new HashMap<String, String>();    
    
    public String encode(String longUrl) {
        UUID randomId = UUID.randomUUID();
        m.put(randomId.toString(), longUrl);
        return randomId.toString();
    }

    public String decode(String shortUrl) {
        if (m.containsKey(shortUrl)) {
            return m.get(shortUrl);
        }
        return "";
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
