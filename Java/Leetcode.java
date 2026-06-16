import java.util.HashMap;
import java.util.TreeSet;

class Pair implements Comparable<Pair>
{
    int first;
    int second;
    public Pair(int first, int second)
    {
        this.first = first;
        this.second = second;
    }
    @Override
    public int compareTo(Pair o)
    {
        if (this.first != o.first)
        {
            return Integer.compare(this.first, o.first);
        }
        return Integer.compare(this.second, o.second);
    }
}
class AuctionSystem {

    HashMap<Integer, HashMap<Integer, Integer>> itemUserMap = new HashMap<>();
    HashMap<Integer, TreeSet<Pair>> itemAmountMap = new HashMap<>();

    public AuctionSystem() {}

    public void addBid(int userId, int itemId, int bidAmount)
    {
        itemUserMap.putIfAbsent(itemId, new HashMap<>());
        itemAmountMap.putIfAbsent(itemId, new TreeSet<>());
        HashMap<Integer, Integer> itemMap = itemUserMap.get(itemId);
        TreeSet<Pair> pairs = itemAmountMap.get(itemId);
        if (itemMap.containsKey(userId))
        {
            int oldAmount = itemMap.get(userId);
            pairs.remove(new Pair(oldAmount, userId));
        }
        itemMap.put(userId, bidAmount);
        pairs.add(new Pair(bidAmount, userId));
    }

    public void updateBid(int userId, int itemId, int newAmount)
    {
        HashMap<Integer, Integer> itemMap = itemUserMap.get(itemId);
        TreeSet<Pair> pairs = itemAmountMap.get(itemId);
        int oldAmount = itemMap.get(userId);
        pairs.remove(new Pair(oldAmount, userId));
        itemMap.put(userId, newAmount);
        pairs.add(new Pair(newAmount, userId));
    }

    public void removeBid(int userId, int itemId)
    {
        HashMap<Integer, Integer> itemMap = itemUserMap.get(itemId);
        TreeSet<Pair> pairs = itemAmountMap.get(itemId);
        int amount = itemMap.get(userId);
        pairs.remove(new Pair(amount, userId));
        itemMap.remove(userId);
    }

    public int getHighestBidder(int itemId)
    {
        if (!itemAmountMap.containsKey(itemId) || itemAmountMap.get(itemId).isEmpty())
        {
            return -1;
        }
        return itemAmountMap.get(itemId).last().second;
    }
}
public class Leetcode
{
    AuctionSystem auctionSystem = new AuctionSystem();
}
