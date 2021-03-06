#include "StorkpandaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<StorkpandaApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

StorkpandaApp::StorkpandaApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  StorkpandaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  StorkpandaApp::associateSyntax(_syntax, _action_factory);
}

StorkpandaApp::~StorkpandaApp()
{
}

// External entry point for dynamic application loading
extern "C" void StorkpandaApp__registerApps() { StorkpandaApp::registerApps(); }
void
StorkpandaApp::registerApps()
{
  registerApp(StorkpandaApp);
}

// External entry point for dynamic object registration
extern "C" void StorkpandaApp__registerObjects(Factory & factory) { StorkpandaApp::registerObjects(factory); }
void
StorkpandaApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void StorkpandaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { StorkpandaApp::associateSyntax(syntax, action_factory); }
void
StorkpandaApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
