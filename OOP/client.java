import java.util.*;

// 抽象原型類 
//抽象公文接口，也可定定義為抽象類，提供clone()方法的實現，將業務方法聲明為抽象方法
interface OfficialDocument extends Cloneable {
	public OfficialDocument clone();

	public void display();
}

// 可行性分析報告(Feasibility Analysis Report)類
class FAR implements OfficialDocument {
	public OfficialDocument clone() {
		OfficialDocument far = null;
		try {
			far = (OfficialDocument) super.clone();
		} catch (CloneNotSupportedException e) {
			System.out.println("不支持複製！");
		}
		return far;
	}

	public void display() {
		System.out.println("《可行性分析報告》");
	}
}

// 軟體需求規格說明書(Software Requirements Specification)類
class SRS implements OfficialDocument {
	public OfficialDocument clone() {
		OfficialDocument srs = null;
		try {
			srs = (OfficialDocument) super.clone();
		} catch (CloneNotSupportedException e) {
			System.out.println("不支持複製！");
		}
		return srs;

	}
	public void display() {
		System.out.println("《軟體需求規格說明書》");
	}
}

// 原型管理器（使用餓漢式單例模式實現）
class PrototypeManager

{
	// 定義一個hash table，用於存儲原型對象
	private Hashtable ht = new Hashtable();
	private static PrototypeManager pm = new PrototypeManager();
	// 為Hash table增加公文對象
	private PrototypeManager() {
		ht.put("far", new FAR());
		ht.put("srs", new SRS());

	}
	// 增加新的公文對象
	public void addOfficialDocument(String key, OfficialDocument doc)
	{
		ht.put(key, doc);
	}

	// 通過淺拷貝獲取新的公文對象
	public OfficialDocument getOfficialDocument(String key) {
		return ((OfficialDocument) ht.get(key)).clone();
	}

	public static PrototypeManager getPrototypeManager() {
		return pm;
	}

}

// 客戶端
public class client {
	public static void main(String[] args) throws CloneNotSupportedException {

		// 獲取原型管理器對象，PrototypeManager是單例類
		PrototypeManager pm = PrototypeManager.getPrototypeManager();


		OfficialDocument doc1, doc2, doc3, doc4;
		doc1 = pm.getOfficialDocument("far");

		doc1.display();

		doc2 = pm.getOfficialDocument("far");

		doc2.display();

		System.out.println(doc1 == doc2); // 簡單驗證兩份可行性分析報告是否是同一個

		doc3 = pm.getOfficialDocument("srs");
		doc3.display();

		doc4 = pm.getOfficialDocument("srs");
		doc4.display();

		System.out.println(doc3 == doc4); // 簡單驗證兩份軟體需求規格報告書是否是同一個
	}
}