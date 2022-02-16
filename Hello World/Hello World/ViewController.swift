//
//  ViewController.swift
//  Hello World
//
//  Created by mac19 on 2022/2/16.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var output: UILabel!
    
    @IBOutlet weak var input: UITextField!
    
    @IBAction func btn(_ sender: UIButton) {
        let controller = UIAlertController(title: "尚未輸入名字", message: "請輸入姓名", preferredStyle: .alert)
        let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
        controller.addAction(okAction)
        
        if input.text! != "Input your name"{
            output.text = "Hello, \(input.text!)"
        }else{
            present(controller, animated: true, completion: nil)
        }
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
}

