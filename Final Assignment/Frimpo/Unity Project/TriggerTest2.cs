using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerTest2 : MonoBehaviour {

    private SteamVR_TrackedObject trackedObject;

    [SerializeField]
    public bool trigger;
    [SerializeField]
    public bool trackpad;
    [SerializeField]
    public bool grip;
    [SerializeField]
    public bool menu;



	// Use this for initialization
	public void Start () {
        trackedObject = GetComponent<SteamVR_TrackedObject>();
	}
	
	// Update is called once per frame
	public void Update () {
        var device = SteamVR_Controller.Input((int)trackedObject.index);

        trigger = device.GetPress(Valve.VR.EVRButtonId.k_EButton_SteamVR_Trigger);
        grip = device.GetPress(Valve.VR.EVRButtonId.k_EButton_Grip);
        trackpad = device.GetPress(Valve.VR.EVRButtonId.k_EButton_SteamVR_Touchpad);
        menu = device.GetPress(Valve.VR.EVRButtonId.k_EButton_ApplicationMenu);
    }
}
