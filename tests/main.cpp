#include<iostream>
#include<Eigen/Core>
#include<Eigen/Lgsm>

#include<xdecore/gvm.h>

int main(int argc, char* argv[]){
    //Mechanical scene
	xde::gvm::SceneRef mechanicalScene = xde::gvm::SceneRef::createObject("mechanicalScene");
	mechanicalScene.setIntegratorFlags(xde::gvm::FRICTION_DYNAMIC_INTEGRATOR);
	mechanicalScene.setTimeStep(1e-3);
	mechanicalScene.setVerticalDirectionUp(Eigen::Vector3d(0., 1.0, 0.0));

    //Create pendulum
	xde::gvm::RigidBodyRef pendulum = xde::gvm::RigidBodyRef::createObject("pendulum");
	pendulum.setMass(1.0);
	pendulum.setPrincipalInertiaFrame(Eigen::Displacementd::Identity());
	pendulum.setPrincipalMomentsOfInertia(Eigen::Vector3d::Constant(1.));

	//Joints
	xde::gvm::HingeJointRef hinge = xde::gvm::HingeJointRef::createObject("hinge");

	Eigen::Vector3d axis(0., 0., 1.);
	Eigen::Vector3d center(0., 0., 0.);
	hinge.configure(Eigen::Displacementd(-1.5, 0., 0., 1.0, 0., 0.), center, axis, 0);
	mechanicalScene.addRigidBodyToGround(pendulum, hinge);

	for(int i=0;i<100;i++){
		mechanicalScene.integrate();
		std::cout << pendulum.getPosition() << std::endl;
	}

	return 1;
}
