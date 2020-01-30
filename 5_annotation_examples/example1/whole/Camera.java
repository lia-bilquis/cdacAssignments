package annotations_basics.whole;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import annotations_basics.parts.CamBattery;
import annotations_basics.parts.Lens;

@Component
public class Camera {

	private CamBattery battery;
	private Lens lens;

	public Camera() {
		System.out.println("Camera object Created!");
		battery = new CamBattery();
	}

	@Autowired
	public void setLens(Lens lens) {
		this.lens = lens;
	}

	public void clickPic() {
		System.out.println(battery.givePower() + "=>" + lens.shutter());
	}
}
