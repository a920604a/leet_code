//按鈕接口：抽象產品
interface Button {
	public void display();
}

//Spring按鈕類：具體產品
class SpringButton implements Button {
	public void display() {
		System.out.println("顯示淺綠色按鈕");
	}
}
 
//Summer按鈕類：具體產品
class SummerButton implements Button {
	public void display() {
		System.out.println("顯示淺藍色按鈕");
	}	
}
 
//文本框接口：抽象產品
interface TextField {
	public void display();
}
 
//Spring文本框類：具體產品
class SpringTextField implements TextField {
	public void display() {
		System.out.println("顯示淺綠色邊框文本框。");
	}
}
 
//Summer文本框類：具體產品
class SummerTextField implements TextField {
	public void display() {
		System.out.println("顯示藍色邊框文本框。");
	}	
}
 
//组合框接口：抽象產品
interface ComboBox {
	public void display();
}
 
//Spring组合框類：具體產品
class SpringComboBox implements ComboBox {
	public void display() {
		System.out.println("顯示綠色邊框組合框。");
	}
}
 
//Summer組合框類：具體產品
class SummerComboBox implements ComboBox {
	public void display() {
		System.out.println("顯示藍色邊框組合框。");
	}	
}
 
//界面主題工廠接口：抽象工廠
interface SkinFactory {
	public Button createButton();
	public TextField createTextField();
	public ComboBox createComboBox();
}
 
//Spring主題工廠：具體工廠 產品族
class SpringSkinFactory implements SkinFactory {
	public Button createButton() {
		return new SpringButton();
	}
 
	public TextField createTextField() {
		return new SpringTextField();
	}
 
	public ComboBox createComboBox() {
		return new SpringComboBox();
	}
}
 
//Summer主題工廠：具體工廠 產品族
class SummerSkinFactory implements SkinFactory {
	public Button createButton() {
		return new SummerButton();
	}
 
	public TextField createTextField() {
		return new SummerTextField();
	}
 
	public ComboBox createComboBox() {
		return new SummerComboBox();
	}
}



class Client {
	public static void main(String args[]) {
        //使用抽象層定義
		SkinFactory factory;
		Button bt;
		TextField tf;
		ComboBox cb;
		// factory = (SkinFactory)XMLUtil.getBean();  // 配置文件配置
        factory = new SpringSkinFactory() ;
        // 不同產品等級的產品，但同品牌，都是 SpringSkinFactory 具體工廠提供
		bt = factory.createButton();
		tf = factory.createTextField();
		cb = factory.createComboBox();
		bt.display();
		tf.display();
		cb.display();
	}
}