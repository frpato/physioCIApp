//
//  C3Connector.swift
//  C3ConnectorProject
//
//  Created by Tine Meidahl Münsberg on 27/09/2017.
//  Copyright © 2017 Tine Meidahl Münsberg. All rights reserved.
//

import Foundation
import opkit
import CoreBluetooth

class ModelC3Connetor: NSObject, OPConnectionManagerDelegate, OPC3SessionDelegate {
    
    var connectionManager: OPConnectionManager
    var device: OPC3Device?
    var session: OPC3SessionDelegate!
    
    override init(){
        connectionManager = OPConnectionManager.sharedInstance()
        super.init()
        connectionManager.delegate = self
    }
    
    func connectionManager(_ manager: OPConnectionManager!, didUpdateState state: ConnectionManagerStates) {
        switch state {
        case .poweredOn:
            manager.startScanning()
            print("Scanning for a device...")
        default:
            print("Bluetooth not enable/ready")
        }
    }
    
    func connectionManagerIsReady(_ manager: OPConnectionManager!){
    }

    
    func connectionManager(_ manager: OPConnectionManager!, didDiscover device: OPC3Device!, estimatedSignalStrength signalStrength: NSNumber!) {
        print("Discovered device")
        manager.connect(device!)
        (print("Connecting device..."))
            print("device: \(device)")
    }
    
    func connectionManager(_ manager: OPConnectionManager!, willConnectTo device: OPC3Device!) {
    }

    
    func connectionManager(_ manager: OPConnectionManager!, didDisconnectFrom device: OPC3Device!){
        print("C3 have been disconnected")
    }
    
    
    func connectionManager(_ manager: OPConnectionManager!, didConnectTo device: OPC3Device!){
        print("C3 is now connected")
        manager.stopScanning()
    }
    
    
    func connectionManager(_ manager: OPConnectionManager!, willDisconnectFrom device: OPC3Device!){
        print("C3 is no longer connected")
    }
    
    
    func connectionManager(_ manager: OPConnectionManager!, didFailToConnectTo device: OPC3Device!, error: Error!){
        print("C3 failed to connect")
    }
    
    func session(session: OPC3Session!, didReadDeviceInformation deviceInformation: OPDeviceInformation!, forDevice device: OPC3Device!){
        print("Device information: \(deviceInformation)")
    }


    func session(session: OPC3Session!, didUpdateEcg1Data ecg1Data: OPC3EcgPackage!, forDevice device: OPC3Device!) {
        let ECGData1 = ecg1Data.ecgFilteredSamples
        print(String(describing: ECGData1))
        print("ECG1 data: \(ecg1Data)")
    }
    
//    func startCortrium(){
//        connectionManager = OPConnectionManager()
//    }
}


@objc public protocol OPC3SessionDelegate: NSObjectProtocol{
    @objc optional func session(session: OPC3Session!, didReadDeviceInformation deviceInformation: OPDeviceInformation!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didUpdateMiscData miscData: OPC3MiscPackage!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didUpdateEcg1Data ecg1Data: OPC3EcgPackage!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didUpdateEcg2Data ecg2Data: OPC3EcgPackage!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didUpdateEcg3Data ecg3Data: OPC3EcgPackage!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didUpdateHeartRate heartRate: OPC3HeartRatePackage!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didReadCurrentMode modeData: OPC3ModePackage!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didUpdateRawPayload rawPayload: NSData!, forDevice device: OPC3Device!)
    @objc optional func session(session: OPC3Session!, didRegisterEvent event: OPC3EventPackage!, forDevice device: OPC3Device!)
}

